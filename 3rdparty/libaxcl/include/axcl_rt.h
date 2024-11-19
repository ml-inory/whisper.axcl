/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_H__
#define __AXCL_RT_H__

#include "axcl_base.h"
#include "axcl_rt_context.h"
#include "axcl_rt_device.h"
#include "axcl_rt_memory.h"
#include "axcl_rt_engine.h"
#include "axcl_rt_stream.h"

#ifdef __cplusplus
extern "C" {
#endif

axclError axclrtGetVersion(int32_t *major, int32_t *minor, int32_t *patch);
const char *axclrtGetSocName();

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_H__ */