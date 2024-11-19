/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AX_VIN_KERNEL_EXT_H__
#define __AX_VIN_KERNEL_EXT_H__

#include "ax_base_type.h"

#define AX_VIN_FTC_LIGHT_PIN_NUM            (10)
#define AX_VIN_MAX_SNS_REGISTER_NUM         (32)
#define AX_VIN_HDR_CHN_NUM                  (4)

#define AX_VIN_SNS_L_FSOF                   (0x00)
#define AX_VIN_SNS_L_FEOF                   (0x01)
#define AX_VIN_SNS_S_FSOF                   (0x10)
#define AX_VIN_SNS_S_FEOF                   (0x11)
#define AX_VIN_SNS_VS_FSOF                  (0x20)
#define AX_VIN_SNS_VS_FEOF                  (0x21)

/************************* sensor register parameters ************************/
typedef union _AX_VIN_SNS_COMMBUS_T_ {
    AX_S8   I2cDev;
    struct {
        AX_S8  bit4SpiDev       : 4;
        AX_S8  bit4SpiCs        : 4;
    } SpiDev;
} AX_VIN_SNS_COMMBUS_T;

typedef enum _AX_VIN_SNS_CONNECT_TYPE_E_ {
    AX_VIN_SNS_CONNECT_I2C = 0,
    AX_VIN_SNS_CONNECT_SPI,
    AX_VIN_SNS_CONNECT_BUTT,
} AX_VIN_SNS_CONNECT_TYPE_E;

typedef struct _AX_VIN_SNS_ISP_I2C_DATA_T_ {
    AX_BOOL bUpdate;            /* AX_TRUE: The sensor registers are written, AX_FALSE: The sensor registers are not written*/
    AX_U8   nDelayFrmNum;       /* Number of frames for register delay configuration */
    AX_U8   nDevAddr;           /* sensor device address */
    AX_U8   nIntPos;            /* Position of the register takes effect, only support SIF_L_FSOF/SIF_S_FSOF */
    AX_U8   reserve[1];
    AX_U32  nRegAddr;           /* register address */
    AX_U32  nAddrByteNum;       /* Bit width of the register address */
    AX_U32  nData;              /* Sensor register data */
    AX_U32  nDataByteNum;       /* Bit width of sensor register data */
} AX_VIN_SNS_ISP_I2C_DATA_T;

typedef struct _AX_VIN_SNS_ISP_SPI_DATA_T_ {
    AX_BOOL bUpdate;
    AX_U8   nDelayFrmNum;       /* Number of frames for register delay configuration */
    AX_U8   nIntPos;            /* Position of the register takes effect */
    AX_U8   reserve[2];
    AX_U32  nDevAddr;           /* Sensor device address */
    AX_U32  nDevAddrByteNum;    /* Bit width of the sensor device address */
    AX_U32  nRegAddr;           /* Sensor register address */
    AX_U32  nRegAddrByteNum;    /* Bit width of the sensor register address */
    AX_U32  nData;              /* Sensor register data*/
    AX_U32  nDataByteNum;       /* Bit width of sensor register data */
} AX_VIN_SNS_ISP_SPI_DATA_T;

typedef struct _AX_VIN_SYNC_PARAM_T_ {
    AX_U32 exp_time[AX_VIN_HDR_CHN_NUM];    /* Exposure Time(us). Accuracy: U32 Range: [0x0, 0xFFFFFFFF] */
    AX_U32 again[AX_VIN_HDR_CHN_NUM];       /* Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF] */
    AX_U32 dgain[AX_VIN_HDR_CHN_NUM];       /* ccuracy: U22.10 Range: [0x400, 0xFFFFFFFF] */
    AX_U32 total_gain[AX_VIN_HDR_CHN_NUM];
    AX_U32 hdr_ratio[AX_VIN_HDR_CHN_NUM-1]; /* Accuracy: U7.10 Range: [0x400, 0x1FC00] */

    AX_U32 isp_dgain;                       /* ISP Dgain value. Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF] */
} AX_VIN_SYNC_PARAM_T;

typedef struct _AX_VIN_SNS_REGS_CFG_TABLE_T_ {
    AX_BOOL                         bConfig;
    AX_VIN_SNS_CONNECT_TYPE_E       eSnsType;
    AX_BOOL                         bQuickEffectEn;

    /*Number of registers requiring timing control. The member value cannot be dynamically changed*/
    AX_U32                          nRegNum;
    /* Maximum number of delayed frames from the time when all sensor registers are configured to the
       time when configurations take effect. Used when ispgain is synchronized with sensor exp registers */
    AX_U32                          nCfg2ValidDelayMax;
    AX_VIN_SNS_COMMBUS_T            tComBus;
    union {
        AX_VIN_SNS_ISP_I2C_DATA_T   sztI2cData[AX_VIN_MAX_SNS_REGISTER_NUM];
        AX_VIN_SNS_ISP_SPI_DATA_T   sztSpiData[AX_VIN_MAX_SNS_REGISTER_NUM];
    } sztData;
    AX_VIN_SYNC_PARAM_T             tSyncParam;  /* from ae result，*/;
} AX_VIN_SNS_REGS_CFG_TABLE_T;

/************************* ftc snap parameters ************************/
typedef enum _ax_vin_ftc_light_type_e_ {
    AX_VIN_FTC_LIGHT_MODE_STROBE,
    AX_VIN_FTC_LIGHT_MODE_FLASH,
    AX_VIN_FTC_LIGHT_MODE_MAX,
} ax_vin_ftc_light_type_e;

typedef enum _ax_vin_sync_polarity_e_ {
    AX_VIN_FTC_POLARITY_HIGH = 0,        /* the valid horizontal/vertical synchronization signal is high-level */
    AX_VIN_FTC_POLARITY_LOW,             /* the valid horizontal/vertical synchronization signal is low-level */
} ax_vin_sync_polarity_e;

typedef struct _ax_vin_ftc_flash_timing_attr_t_ {
    AX_U32                          nLightIdx;
    AX_U32                          bUpdate;
    ax_vin_sync_polarity_e          eLightSyncInv;
    AX_U32                          nLightDutyTime;
    AX_S32                          nLightDelayTime;
} ax_vin_ftc_flash_timing_attr_t;

typedef enum _ax_vin_ftc_cmd_type_e_ {
    AX_VIN_FTC_CMD_MODE_REPLACE_FLASH,
    AX_VIN_FTC_CMD_MODE_INSERT,
    AX_VIN_FTC_CMD_MODE_MAX,
} ax_vin_ftc_cmd_type_e;

typedef struct _ax_vin_ftc_flash_cmd_attr_t_ {
    AX_U32                          nCmdLightIdx;
    AX_U32                          bCmdUpdate;
    ax_vin_ftc_cmd_type_e           eCmdType;
    AX_U32                          nCmdBitWidth;
    AX_U32                          nCmdTimeWidth;
    AX_U32                          nCmdData;
} ax_vin_ftc_flash_cmd_attr_t;

typedef enum _ax_vin_ftc_trigger_selection_e {
    AX_VIN_FTC_LIGHT_TRIGGER_INSERT,
    AX_VIN_FTC_LIGHT_TRIGGER_REPLACE_CURRENT,
    AX_VIN_FTC_LIGHT_TRIGGER_REPLACE_VIDEO,
    AX_VIN_FTC_LIGHT_TRIGGER_REPLACE_PICTURE,
} ax_vin_ftc_trigger_selection_e;

typedef struct _ax_vin_ftc_flash_trigger_data_t_ {
    AX_U32                          nTriggerNum;
    ax_vin_ftc_trigger_selection_e  eTriggerSelect;
    AX_U64                          nUserData;
    AX_U64                          nTriggerPts;
} ax_vin_ftc_flash_trigger_data_t;

typedef struct _ax_vin_ftc_snap_event_info_t_ {
    AX_U32                          nLightIdx;
    AX_BOOL                         bLightEnable;
    ax_vin_ftc_flash_trigger_data_t tTriggerData;
} ax_vin_ftc_snap_event_info_t;

typedef struct _ax_vin_ftc_snap_param_t_ {
    ax_vin_ftc_flash_timing_attr_t      tFlashAttr[AX_VIN_FTC_LIGHT_PIN_NUM];
    ax_vin_ftc_flash_cmd_attr_t         tCmdAttr[AX_VIN_FTC_LIGHT_PIN_NUM];
    ax_vin_ftc_snap_event_info_t        tSnapInfo[AX_VIN_FTC_LIGHT_PIN_NUM];
} ax_vin_ftc_snap_param_t;

typedef struct _ax_vin_ftc_strobe_timing_attr_t_ {
    ax_vin_sync_polarity_e      eStrobeSyncInv;     /* the strobe sync signal polarity */
    AX_U32                      nStrobeDutyTime;    /* the strobe permillage 0‰ ~ 1000‰ */
    AX_U32                      nStrobeDelayTime;   /* the sync trigger freq permillage 0‰ ~ 1000‰ */
    AX_U32                      nStrobeFreqRatio;   /* the Strobe Freq ratio 0x1 = 1, 0x2 = 2, 0x82 = 0.5 */
} ax_vin_ftc_strobe_timing_attr_t;

typedef struct _AX_VIN_BUS_CALLBACK_T_ {
    AX_S32 (*pfn_vin_i2c_write)(AX_U8 i2c_dev, AX_U8 dev_addr,
                                 AX_U32 reg_addr, AX_U32 reg_addr_num,
                                 AX_U32 data, AX_U32 data_byte_num);

    AX_S32 (*pfn_vin_spi_write)(AX_U8 spi_dev, AX_U8 spi_csn,
                                   AX_U32 dev_addr, AX_U32 dev_addr_num,
                                   AX_U32 reg_addr, AX_U32 reg_addr_num,
                                   AX_U32 data, AX_U32 data_byte_num);

    AX_S32 (*pfn_vin_spi_read)(AX_U8 spi_dev, AX_U8 spi_csn,
                                   AX_U32 dev_addr, AX_U32 dev_addr_num,
                                   AX_U32 reg_addr, AX_U32 reg_addr_num,
                                   AX_U32 *pdata, AX_U32 data_byte_num);
} AX_VIN_BUS_CALLBACK_T;

#define AX_MSENSOR_MAX_DATA_NUM 129
typedef struct {
    AX_U32 x;
    AX_U32 y;
    AX_U32 z;
} ax_msensor_sample_data;

typedef struct {
    ax_msensor_sample_data gyro_data[AX_MSENSOR_MAX_DATA_NUM];
    ax_msensor_sample_data acc_data[AX_MSENSOR_MAX_DATA_NUM];
    AX_U32 temperature[AX_MSENSOR_MAX_DATA_NUM];
    AX_U32 timestamp[AX_MSENSOR_MAX_DATA_NUM];
} ax_msensor_data;

typedef struct _ax_msensor_fifo_data_t_ {
    AX_U64 pkg_cnt;
    AX_U64 pts_us;
    AX_U64 read_time;
    ax_msensor_data data;
} ax_msensor_fifo_data_t;

typedef struct _AX_VIN_PYRO_CALLBACK_T_ {
    /* pyro data read */
    AX_S32 (*pfn_vin_pyro_read_data)(ax_msensor_fifo_data_t *pdata);
} AX_VIN_PYRO_CALLBACK_T;

typedef enum {
    AX_VIN_INT_TYPE_SNS_FSOF    = 0,
    AX_VIN_INT_TYPE_SNS_FEOF    = 1,
    AX_VIN_INT_TYPE_MAX,
} ax_vin_interrupt_type_e;

typedef struct _ax_vin_int_notify_callback_t_ {
    AX_S32 (*pfn_vin_interrupt_event_handling)(ax_vin_interrupt_type_e int_type, AX_VOID *pdata);
} ax_vin_int_notify_callback_t;

typedef AX_S32 (*int_callback)(ax_vin_interrupt_type_e int_type, AX_VOID *);
typedef struct _AX_VIN_KERNEL_EXPORT_FUNC_T_ {
    /* sensor api */
    AX_S32 (*pfn_vin_sns_register_bus_callback)(AX_U8 dev_id, AX_VIN_SNS_CONNECT_TYPE_E bus_type, AX_VIN_BUS_CALLBACK_T *bus_callback);
    AX_S32 (*pfn_vin_sns_set_reg_info)(AX_U8 pipe_id, AX_VIN_SNS_REGS_CFG_TABLE_T *sns_reg_info);
    AX_S32 (*pfn_vin_sns_freeze_commbus)(AX_U8 dev_id, AX_BOOL bFreeze, AX_S32 timeout_ms);

    /* strobe api */
    AX_S32 (*pfn_vin_ftc_set_strobe_timing_attr)(AX_U8 dev_id, AX_U8 strobe_idx, ax_vin_ftc_strobe_timing_attr_t *strobe_attr);
    AX_S32 (*pfn_vin_ftc_get_strobe_timing_attr)(AX_U8 dev_id, AX_U8 strobe_idx, ax_vin_ftc_strobe_timing_attr_t *strobe_attr);
    AX_S32 (*pfn_vin_ftc_enable_strobe)(AX_U8 dev_id, AX_U8 strobe_idx);
    AX_S32 (*pfn_vin_ftc_disable_strobe)(AX_U8 dev_id, AX_U8 strobe_idx);

    /* flash snap api */
    AX_S32 (*pfn_vin_ftc_set_snap_param)(AX_U8 dev_id, ax_vin_ftc_snap_param_t *snap_param);
    AX_S32 (*pfn_vin_ftc_get_snap_param)(AX_U8 dev_id, ax_vin_ftc_snap_param_t *snap_param);

    /* pyro api */
    AX_S32 (*pfn_vin_pyro_register_callback)(AX_VIN_PYRO_CALLBACK_T *pyro_callback);

    /* interrupt notification api */
    AX_S32 (*pfn_vin_int_notify_register_callback)(AX_U8 dev_id, int_callback cb);
} AX_VIN_KERNEL_EXPORT_FUNC_T;


// AX VIN DRIVER EXPORT API
extern AX_VIN_KERNEL_EXPORT_FUNC_T ax_vin_kernel_ext_handle;// AX VIN DRIVER DEFINED

#define CB_VIN_FTC_SetSnapParam(dev_id, snap_param)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_set_snap_param(dev_id, snap_param)

#define CB_VIN_FTC_GetSnapParam(dev_id, snap_param)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_get_snap_param(dev_id, snap_param)


#define CB_VIN_FTC_RegisterBusCallback(dev_id, bus_type, bus_callback)\
    ax_vin_kernel_ext_handle.pfn_vin_sns_register_bus_callback(dev_id, bus_type, bus_callback)

#define CB_VIN_FTC_SetSnsRegInfo(dev_id, sns_reg_info)\
    ax_vin_kernel_ext_handle.pfn_vin_sns_set_reg_info(dev_id, sns_reg_info)

#define CB_VIN_FTC_FreezeCommBus(dev_id, bFreeze, timeout_ms)\
    ax_vin_kernel_ext_handle.pfn_vin_sns_freeze_commbus(dev_id, bFreeze, timeout_ms)

#define CB_VIN_FTC_SetStrobeTimingAttr(dev_id, strobe_idx, strobe_attr)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_set_strobe_timing_attr(dev_id, strobe_idx, strobe_attr)

#define CB_VIN_FTC_GetStrobeTimingAttr(dev_id, strobe_idx, strobe_attr)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_get_strobe_timing_attr(dev_id, strobe_idx, strobe_attr)

#define CB_VIN_FTC_EnableStrobe(dev_id, strobe_idx)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_enable_strobe(dev_id, strobe_idx)

#define CB_VIN_FTC_DisableStrobe(dev_id, strobe_idx)\
    ax_vin_kernel_ext_handle.pfn_vin_ftc_disable_strobe(dev_id, strobe_idx)

#define CB_VIN_PRYO_RegisterCallback(pyro_callback)\
    ax_vin_kernel_ext_handle.pfn_vin_pyro_register_callback(pyro_callback)

#define CB_VIN_INT_Notify_RegisterCallback(dev_id, int_callback)\
    ax_vin_kernel_ext_handle.pfn_vin_int_notify_register_callback(dev_id, int_callback)

//CHECK FUNC NULL
#define CHECK_CB_VIN_FTC_SetSnapParam()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_set_snap_param)
#define CHECK_CB_VIN_FTC_GetSnapParam()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_get_snap_param)

#define CHECK_CB_VIN_FTC_RegisterBusCallback()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_sns_register_bus_callback)

#define CHECK_CB_VIN_FTC_SetSnsRegInfo()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_sns_set_reg_info)

#define CHECK_CB_VIN_FTC_FreezeCommBus()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_sns_freeze_commbus)

#define CHECK_CB_VIN_FTC_SetStrobeTimingAttr()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_set_strobe_timing_attr)

#define CHECK_CB_VIN_FTC_GetStrobeTimingAttr()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_get_strobe_timing_attr)

#define CHECK_CB_VIN_FTC_EnableStrobe()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_enable_strobe)

#define CHECK_CB_VIN_FTC_DisableStrobe()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_ftc_disable_strobe)

#define CHECK_CB_VIN_PYRO_RegisterCallback()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_pyro_register_callback)

#define CHECK_CB_VIN_INT_Notify_RegisterCallback()\
    (AX_NULL != ax_vin_kernel_ext_handle.pfn_vin_int_notify_register_callback)

#endif //__AX_VIN_KERNEL_EXT_H__
