/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_CONTEXT_H__
#define __AXCL_RT_CONTEXT_H__

#include "axcl_rt_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AXCL_DEF_CONTEXT_ERR(e)              AXCL_DEF_RUNTIME_ERR(AXCL_RUNTIME_CONTEXT, (e))

#define AXCL_ERR_CONTEXT_NULL_POINTER        AXCL_DEF_CONTEXT_ERR(AXCL_ERR_NULL_POINTER)
#define AXCL_ERR_CONTEXT_CREATE              AXCL_DEF_CONTEXT_ERR(0x81)
#define AXCL_ERR_CONTEXT_DESTROY             AXCL_DEF_CONTEXT_ERR(0x82)
#define AXCL_ERR_CONTEXT_BIND_THREAD         AXCL_DEF_CONTEXT_ERR(0x83)
#define AXCL_ERR_CONTEXT_NO_BIND_CONTEXT     AXCL_DEF_CONTEXT_ERR(0x84)

axclError axclrtCreateContext(axclrtContext *context, int32_t deviceId);
axclError axclrtDestroyContext(axclrtContext context);
axclError axclrtSetCurrentContext(axclrtContext context);
axclError axclrtGetCurrentContext(axclrtContext *context);
axclError axclrtGetDefaultContext(axclrtContext *context, int32_t deviceId);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_CONTEXT_H__ */