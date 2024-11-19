/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_DEVICE_H__
#define __AXCL_RT_DEVICE_H__

#include "axcl_rt_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AXCL_DEF_DEVICE_ERR(e)              AXCL_DEF_RUNTIME_ERR(AXCL_RUNTIME_DEVICE, (e))

#define AXCL_ERR_DEVICE_NULL_POINTER        AXCL_DEF_DEVICE_ERR(AXCL_ERR_NULL_POINTER)
#define AXCL_ERR_DEVICE_OPEN                AXCL_DEF_DEVICE_ERR(AXCL_ERR_OPEN)
#define AXCL_ERR_DEVICE_UNSUPPORT           AXCL_DEF_DEVICE_ERR(AXCL_ERR_UNSUPPORT)

#define AXCL_ERR_DEVICE_QUERY_DEVICE        AXCL_DEF_DEVICE_ERR(0x80)
#define AXCL_ERR_DEVICE_NO_CONNECT          AXCL_DEF_DEVICE_ERR(0x81)
#define AXCL_ERR_DEVICE_PROBE               AXCL_DEF_DEVICE_ERR(0x82)
#define AXCL_ERR_DEVICE_NOT_ACTIVE          AXCL_DEF_DEVICE_ERR(0x83)
#define AXCL_ERR_DEVICE_INVALID_ID          AXCL_DEF_DEVICE_ERR(0x84)
#define AXCL_ERR_DEVICE_NO_ACTIVE_DEVICE    AXCL_DEF_DEVICE_ERR(0x85)

axclError axclrtSetDevice(int32_t deviceId);
axclError axclrtResetDevice(int32_t deviceId);
axclError axclrtGetDevice(int32_t *deviceId);
axclError axclrtGetDeviceCount(uint32_t *count);
axclError axclrtGetDeviceList(axclrtDeviceList *deviceList);
axclError axclrtSynchronizeDevice();
axclError axclrtGetDeviceUtilizationRate(int32_t deviceId, axclrtUtilizationInfo *utilizationInfo);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_DEVICE_H__ */