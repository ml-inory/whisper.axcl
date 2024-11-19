/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_TYPE_H__
#define __AXCL_RT_TYPE_H__

#include "axcl_base.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct axclrtUtilizationExtendInfo axclrtUtilizationExtendInfo;
typedef struct axclrtUtilizationInfo {
    int32_t cpuUtilization;
    int32_t npuUtilization;
    int32_t memUtilization;
    axclrtUtilizationExtendInfo *extUtilization;  //!< reserved parameters, current version needs to be null
} axclrtUtilizationInfo;

typedef struct axclrtDeviceList {
    uint32_t num;
    int32_t devices[AXCL_MAX_DEVICE_COUNT];
} axclrtDeviceList;

typedef enum axclrtMemMallocPolicy {
    AXCL_MEM_MALLOC_HUGE_FIRST,
    AXCL_MEM_MALLOC_HUGE_ONLY,
    AXCL_MEM_MALLOC_NORMAL_ONLY
} axclrtMemMallocPolicy;

typedef enum axclrtMemcpyKind {
    AXCL_MEMCPY_HOST_TO_HOST,
    AXCL_MEMCPY_HOST_TO_DEVICE,     //!< host vir -> device phy
    AXCL_MEMCPY_DEVICE_TO_HOST,     //!< host vir <- device phy
    AXCL_MEMCPY_DEVICE_TO_DEVICE,
    AXCL_MEMCPY_HOST_PHY_TO_DEVICE, //!< host phy -> device phy
    AXCL_MEMCPY_DEVICE_TO_HOST_PHY, //!< host phy <- device phy
} axclrtMemcpyKind;

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_TYPE_H__ */
