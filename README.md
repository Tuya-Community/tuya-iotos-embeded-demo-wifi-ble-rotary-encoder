# Tuya IoTOS Embedded Demo WiFi & BLE Rotary Encoder

[English](./README.md) | [中文](./README_zh.md) 

<br>

## Introduction 

This demo is based on [Tuya IoT Platform](https://iot.tuya.com/), Tuya Smart APP, IoTOS Embeded WiFi&Ble SDK, using Tuya WiFi/WiFi+Ble series modules quickly build a rotary encoder detection application . When the rotary encoder rotates clockwise, the gear increases by 1, and the lights turn on in sequence; when the rotary encoder rotates counterclockwise, the gear decreases by 1, and the lights turn off in turn.

<br>


## Quick start 

### Compile & Burn

- After creating a product on [Tuya IoT Platform](https://iot.tuya.com/), download the SDK from the development materials of hardware development.

- Download the demo to the demos directory of the SDK:

  ```bash
  $ cd demos
  $ git clone https://github.com/Tuya-Community/tuya-iotos-embeded-demo-wifi-ble-rotary-encoder.git
  ```

  (Note: The build.sh in the Demo is only required to be used in the SDK below version 2.0.3.)

- Execute the following command in the SDK root directory to start compiling:

  ```bash
  sh build_app.sh demos/tuya_demo_rotary_encoder tuya_demo_rotary_encoder 1.0.0
  ```

- Firmware burn-in license information please refer to: [General Wi-Fi SDK programming authorization instructions](https://developer.tuya.com/cn/docs/iot/tuya-common-wifi-sdk-burning-and-authorization?id=K9ip0gbawnkn7)  

<br>

### File description 

```
├── src         /* Source code files */
|    ├── driver
|    |    └── tuya_rotary.c       /* Rotary encoder detection driver */
|    ├── tuya_device.c            /* Entry file of application layer */
|    ├── tuya_dp_process.c        /* DP process */
|    ├── tuya_app_led.c           /* LED control */
|    └── tuya_app_rotary.c        /* Rotary encoder application */
|
└── include     /* Header files */
     ├── driver
     |    └── tuya_rotary.h       /* Rotary encoder detection driver */
     ├── tuya_device.h            /* Entry file of application layer */
     ├── tuya_dp_process.h        /* DP process */
     ├── tuya_app_led.h           /* LED control */
     └── tuya_app_rotary.h        /* Rotary encoder application */
```

<br>

### Entry to application

Entry file: /demos/src/tuya_device.c

Important function：`device_init()`

- Call the `tuya_iot_wf_soc_dev_init_param()` interface to initialize the SDK, configure the working mode, network distribution mode, and register various callback functions and save the firmware key and PID.
- Call the `tuya_iot_reg_get_wf_nw_stat_cb()` interface to register the device network status callback function.

<br>

### Data point (DP)

- Report dp point interface: dev_report_dp_json_async()

| Function name | OPERATE_RET dev_report_dp_json_async(IN CONST CHAR_T *dev_id,IN CONST TY_OBJ_DP_S *dp_data,IN CONST UINT_T cnt) |
| ------------- | ------------------------------------------------------------ |
| devid         | device id (if gateway, MCU, SOC class device then devid = NULL; if sub-device, then devid = sub-device_id) |
| dp_data       | dp structure array name                                      |
| cnt           | Number of elements of the dp structure array                 |
| Return        | OPRT_OK: Success Other: Failure                              |

<br>

### I/O list

| 外设             | I/O  | 外设      | I/O  |
| ---------------- | ---- | --------- | ---- |
| Rotary encoder-A | PA18 | Gear led1 | PA9  |
| Rotary encoder-B | PA0  | Gear led2 | PA2  |
| LED dimmer       | PA12 | Gear led3 | PA3  |
| Net led          | RX   | Gear led4 | PA4  |

<br>

## Reference

- [General Wi-Fi SDK Instruction](https://developer.tuya.com/en/docs/iot/tuya-common-wifi-sdk?id=K9glcmvw4u9ml) 
- [General Wi-Fi SDK Demo Instruction](https://developer.tuya.com/en/docs/iot/tuya-wifi-sdk-demo-instructions?id=K9oce5ayw5xem) 
- [Tuya Project Hub](https://developer.tuya.com/demo)

<br>

## Technical Support

You can get support from Tuya with the following methods:

- [Tuya IoT Developer Platform](https://developer.tuya.com/en/)
- [Help Center](https://support.tuya.com/en/help)
- [Service & Support](https://service.console.tuya.com)

<br>

