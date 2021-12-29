/**
 * @file tuya_app_rotary.h
 * @author lifan
 * @brief 旋钮编码器应用模块
 * @version 1.0
 * @date 2021-07-30
 *
 * @copyright Copyright (c) tuya.inc 2021
 *
 */

#ifndef __TUYA_APP_ROTARY_H__
#define __TUYA_APP_ROTARY_H__

#include "tuya_cloud_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
************************micro define************************
***********************************************************/

/***********************************************************
***********************typedef define***********************
***********************************************************/

/***********************************************************
***********************variable define**********************
***********************************************************/
extern UCHAR_T sg_gear;

/***********************************************************
***********************function define**********************
***********************************************************/
VOID_T app_rotary_init(VOID_T);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TUYA_APP_ROTARY_H__ */