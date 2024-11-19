/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_RT_MEMORY_H__
#define __AXCL_RT_MEMORY_H__

#include "axcl_rt_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AXCL_DEF_MEMORY_ERR(e)              AXCL_DEF_RUNTIME_ERR(AXCL_RUNTIME_MEMORY, (e))

#define AXCL_ERR_MEMORY_NULL_POINTER        AXCL_DEF_MEMORY_ERR(AXCL_ERR_NULL_POINTER)
#define AXCL_ERR_MEMORY_ENCODE              AXCL_DEF_MEMORY_ERR(AXCL_ERR_ENCODE)
#define AXCL_ERR_MEMORY_DECODE              AXCL_DEF_MEMORY_ERR(AXCL_ERR_DECODE)
#define AXCL_ERR_MEMORY_UNEXPECT_RESPONSE   AXCL_DEF_MEMORY_ERR(AXCL_ERR_UNEXPECT_RESPONSE)
#define AXCL_ERR_MEMORY_EXECUTE_FAIL        AXCL_DEF_MEMORY_ERR(AXCL_ERR_EXECUTE_FAIL)

#define AXCL_ERR_MEMORY_NOT_DEVICE_MEMORY   AXCL_DEF_MEMORY_ERR(0x81)


axclError axclrtMalloc(void **devPtr, size_t size, axclrtMemMallocPolicy policy);
axclError axclrtMallocCached(void **devPtr, size_t size, axclrtMemMallocPolicy policy);
axclError axclrtFree(void *devPtr);
axclError axclrtMemFlush(void *devPtr, size_t size);
axclError axclrtMemInvalidate(void *devPtr, size_t size);
axclError axclrtMallocHost(void **hostPtr, size_t size);
axclError axclrtFreeHost(void *hostPtr);
axclError axclrtMemset(void *devPtr, uint8_t value, size_t count);
axclError axclrtMemcpy(void *dstPtr, const void *srcPtr, size_t count, axclrtMemcpyKind kind);
axclError axclrtMemcmp(const void *devPtr1, const void *devPtr2, size_t count); //!< device memories only

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_MEMORY_H__ */