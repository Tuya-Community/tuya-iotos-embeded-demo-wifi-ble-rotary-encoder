/**
 * @file tuya_app_rotary.c
 * @author lifan
 * @brief 旋钮编码器应用模块
 * @version 1.0
 * @date 2021-08-02
 *
 * @copyright Copyright (c) tuya.inc 2021
 *
 */

#include "tuya_app_rotary.h"
#include "tuya_app_led.h"
#include "tuya_rotary.h"
#include "tuya_gpio.h"
#include "tuya_dp_process.h"
#include "uni_log.h"

/***********************************************************
************************micro define************************
***********************************************************/
/* Pin */
#define P_ROTARY_A  TY_GPIOA_18   /* 旋钮编码器-A */
#define P_ROTARY_B  TY_GPIOA_0    /* 旋钮编码器-B */

#define FAN_GEAR_NUM    4

/***********************************************************
***********************typedef define***********************
***********************************************************/

/***********************************************************
***********************variable define**********************
***********************************************************/
UCHAR_T sg_gear = 0;

VOID_T app_rotary_cb(BOOL_T dir);
ROTARY_USER_DEF_S g_rotary_def = {
    .port_a = P_ROTARY_A,
    .port_b = P_ROTARY_B,
    .call_back = app_rotary_cb
};

/***********************************************************
***********************function define**********************
***********************************************************/
/**
 * @brief   旋钮编码器回调函数
 * @param   dir: 旋转方向 TRUE-顺时针 FALSE-逆时针
 * @return  none
 */
VOID_T app_rotary_cb(BOOL_T dir)
{
    if (dir) {
        PR_NOTICE("The direction of rotation is CW.");
        sg_gear = (sg_gear >= (FAN_GEAR_NUM-1)) ? (FAN_GEAR_NUM-1) : (sg_gear+1);
    } else {
        PR_NOTICE("The direction of rotation is CCW.");
        sg_gear = (sg_gear <= 0) ? (0) : (sg_gear-1);
    }
    PR_NOTICE("current gear is : %d", sg_gear);
    app_set_gear_led(sg_gear);
    report_all_dp_status();
}

/**
 * @brief   旋钮编码器初始化
 * @param   none
 * @return  none
 */
VOID_T app_rotary_init(VOID_T)
{
    OPERATE_RET opRet;
    /* 初始化 */
    opRet = rotary_init(NULL, 0);
    if (opRet != OPRT_OK) {
        PR_ERR("rotary_init err:%d", opRet);
        return;
    }
    opRet = reg_proc_rotary(&g_rotary_def);
    if (opRet != OPRT_OK) {
        PR_ERR("reg_proc_rotary err:%d", opRet);
    }
}
