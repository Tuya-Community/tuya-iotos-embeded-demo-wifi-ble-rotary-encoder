/**
 * @file tuya_dp_process.c
 * @author lifan
 * @brief DP信息处理模块
 * @version 1.0
 * @date 2021-08-02
 *
 * @copyright Copyright (c) tuya.inc 2021
 *
 */

#include "tuya_dp_process.h"
#include "tuya_app_led.h"
#include "tuya_app_rotary.h"
#include "tuya_iot_wifi_api.h"
#include "uni_log.h"
#include "gw_intf.h"
#include <string.h>

/***********************************************************
************************micro define************************
***********************************************************/
/* DP ID */
#define DP_ID_GEAR              102
/* DP amount */
#define FAN_DP_AMOUNT           1

/***********************************************************
***********************typedef define***********************
***********************************************************/

/***********************************************************
***********************variable define**********************
***********************************************************/

/***********************************************************
***********************function define**********************
***********************************************************/
/**
 * @brief   上报所有dp点
 * @param   none
 * @return  none
 */
VOID_T report_all_dp_status(VOID_T)
{
    OPERATE_RET op_ret = OPRT_OK;

    /* 没有连接到路由器，退出 */
    GW_WIFI_NW_STAT_E wifi_state = STAT_LOW_POWER;
    get_wf_gw_nw_status(&wifi_state);
    if (wifi_state <= STAT_AP_STA_DISC || wifi_state == STAT_STA_DISC) {
        return;
    }
    TY_OBJ_DP_S *dp_arr = (TY_OBJ_DP_S *)Malloc(FAN_DP_AMOUNT*SIZEOF(TY_OBJ_DP_S));

    if(NULL == dp_arr) {
        PR_ERR("malloc failed");
        return;
    }

    memset(dp_arr, 0, FAN_DP_AMOUNT*SIZEOF(TY_OBJ_DP_S));

    dp_arr[0].dpid = DP_ID_GEAR;
    dp_arr[0].type = PROP_VALUE;
    dp_arr[0].time_stamp = 0;
    dp_arr[0].value.dp_value = sg_gear;

    op_ret = dev_report_dp_json_async(NULL, dp_arr, FAN_DP_AMOUNT);
    Free(dp_arr);
    if (OPRT_OK != op_ret) {
        PR_ERR("dev_report_dp_json_async relay_config data error, err_num: %d", op_ret);
    }

    PR_DEBUG("dp_query report_all_dp_data");
}

/**
 * @brief   处理dp信息
 * @param   root: dp信息
 * @return  none
 */
VOID_T deal_dp_proc(IN CONST TY_OBJ_DP_S *root)
{
    UCHAR_T dpid;

    dpid = root->dpid;
    PR_NOTICE("dpid:%d", dpid);

    switch(dpid) {
    case DP_ID_GEAR:
        PR_NOTICE("root->value.dp_value:%d", root->value.dp_value);
        sg_gear = (UCHAR_T)root->value.dp_value;
        app_set_gear_led(sg_gear);
        break;
    default:
        break;
    }
}
