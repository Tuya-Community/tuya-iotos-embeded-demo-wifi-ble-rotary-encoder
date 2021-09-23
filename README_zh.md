# Tuya IoTOS Embedded Demo WiFi & BLE Rotary Encoder

[English](./README.md) | [中文](./README_zh.md)

<br>

## 简介 

本 demo 基于 [涂鸦IoT平台](https://iot.tuya.com/) 、涂鸦智能APP、IoTOS Embeded WiFi & Ble SDK，使用涂鸦WiFi/WiFi+BLE系列模组快速组建一个旋钮编码器检测应用。旋钮顺时针旋转时，挡位增加1，指示灯依次点亮；旋钮逆时针旋转时，挡位减小1，指示灯依次熄灭。

<br>

## 快速上手

### 编译与烧录

-  在 [涂鸦IoT平台](https://iot.tuya.com/) 上创建产品后，在硬件开发的开发资料中下载 SDK。

- 下载Demo至SDK目录的demos目录下：

  ```bash
  $ cd demos
  $ git clone https://github.com/Tuya-Community/tuya-iotos-embeded-demo-wifi-ble-rotary-encoder.git
  ```

  （注：Demo中的build.sh仅在版本2.0.3以下的SDK中需要使用。）

- 在SDK根目录下执行以下命令开始编译：

  ```bash
  sh build_app.sh demos/tuya_demo_rotary_encoder tuya_demo_rotary_encoder 1.0.0
  ```

- 固件烧录授权相关信息请参考：[通用 Wi-Fi SDK 烧录授权说明](https://developer.tuya.com/cn/docs/iot/tuya-common-wifi-sdk-burning-and-authorization?id=K9ip0gbawnkn7) 

<br>

### 文件介绍
```
├── src         /* 源文件目录 */
|    ├── driver
|    |    └── tuya_rotary.c       /* 旋钮编码器检测 */
|    ├── tuya_device.c            /* 应用层入口文件 */
|    ├── tuya_dp_process.c        /* dp数据处理 */
|    ├── tuya_app_led.c           /* 指示灯控制 */
|    └── tuya_app_rotary.c        /* 旋钮编码器应用 */
|
└── include     /* 头文件目录 */
     ├── driver
     |    └── tuya_rotary.h       /* 旋钮编码器检测 */
     ├── tuya_device.h            /* 应用层入口文件 */
     ├── tuya_dp_process.h        /* dp数据处理 */
     ├── tuya_app_led.h           /* 指示灯控制 */
     └── tuya_app_rotary.h        /* 旋钮编码器应用 */
```

<br>

### 应用入口
入口文件：`/demos/src/tuya_device.c`

重要函数：`device_init()`

+ 调用 `tuya_iot_wf_soc_dev_init_param()` 接口进行SDK初始化，配置了工作模式、配网模式，同时注册了各种回调函数并存入了固件key和PID。
+ 调用 `tuya_iot_reg_get_wf_nw_stat_cb()`接口注册设备网络状态回调函数。

<br>

### DP点相关

- 上报dp点接口：`dev_report_dp_json_async()`

| 函数名  | OPERATE_RET dev_report_dp_json_async(IN CONST CHAR_T *dev_id,IN CONST TY_OBJ_DP_S *dp_data,IN CONST UINT_T cnt) |
| ------- | ------------------------------------------------------------ |
| devid   | 设备id（若为网关、MCU、SOC类设备则devid = NULL；若为子设备，则devid = sub-device_id) |
| dp_data | dp结构体数组名                                               |
| cnt     | dp结构体数组的元素个数                                       |
| Return  | OPRT_OK：成功  Other：失败                                   |

<br>

### I/O 列表

| 外设           | I/O  | 外设        | I/O  |
| -------------- | ---- | ----------- | ---- |
| 旋钮编码器-A   | PA18 | 挡位指示灯1 | PA9  |
| 旋钮编码器-B   | PA0  | 挡位指示灯2 | PA2  |
| 指示灯亮度调节 | PA12 | 挡位指示灯3 | PA3  |
| 配网状态指示灯 | RX   | 挡位指示灯4 | PA4  |

<br>

## 相关文档

- [通用 Wi-Fi SDK 说明](https://developer.tuya.com/cn/docs/iot/tuya-common-wifi-sdk?id=K9glcmvw4u9ml) 
- [通用 Wi-Fi SDK Demo 说明](https://developer.tuya.com/cn/docs/iot/tuya-wifi-sdk-demo-instructions?id=K9oce5ayw5xem) 
- [涂鸦 Demo 中心](https://developer.tuya.com/demo) 

<br>


## 技术支持

您可以通过以下方法获得涂鸦的支持:

- [涂鸦 AI+IoT 开发者平台](https://developer.tuya.com)
- [帮助中心](https://support.tuya.com/help)
- [服务与支持](https://service.console.tuya.com)

<br>

