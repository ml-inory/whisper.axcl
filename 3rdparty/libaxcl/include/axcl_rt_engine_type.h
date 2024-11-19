/**
 * @file axcl_rt_engine.h
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
**/

#ifndef __AXCL_RT_ENGINE_TYPE_H__
#define __AXCL_RT_ENGINE_TYPE_H__

#include "axcl_rt_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AXCL_DEF_ENGINE_ERR(e)              AXCL_DEF_RUNTIME_ERR(AXCL_RUNTIME_ENGINE, (e))

#define AXCL_ERR_ENGINE_NULL_POINTER        AXCL_DEF_ENGINE_ERR(AXCL_ERR_NULL_POINTER)
#define AXCL_ERR_ENGINE_ILLEGAL_PARAM       AXCL_DEF_ENGINE_ERR(AXCL_ERR_ILLEGAL_PARAM)
#define AXCL_ERR_ENGINE_AXCL_UNSUPPORTED    AXCL_DEF_ENGINE_ERR(AXCL_ERR_UNSUPPORT)
#define AXCL_ERR_ENGINE_ENCODE              AXCL_DEF_ENGINE_ERR(AXCL_ERR_ENCODE)
#define AXCL_ERR_ENGINE_DECODE              AXCL_DEF_ENGINE_ERR(AXCL_ERR_DECODE)
#define AXCL_ERR_ENGINE_UNEXPECT_RESPONSE   AXCL_DEF_ENGINE_ERR(AXCL_ERR_UNEXPECT_RESPONSE)
#define AXCL_ERR_ENGINE_EXECUTE_FAIL        AXCL_DEF_ENGINE_ERR(AXCL_ERR_EXECUTE_FAIL)

#define AXCL_ERR_ENGINE_INVALID_INDEX       AXCL_DEF_ENGINE_ERR(0x81)

#define AXCLRT_ENGINE_MAX_DIM_CNT 32

typedef void* axclrtEvent;
typedef void* axclrtContext;
typedef void* axclrtStream;
typedef void* axclrtEngineIOInfo;
typedef void* axclrtEngineIO;

typedef uint32_t axclrtEngineSet;

typedef enum axclrtEngineModelKind {
    AXCL_MODEL_TYPE_1CORE = 0,
    AXCL_MODEL_TYPE_2CORE = 1,
    AXCL_MODEL_TYPE_3CORE = 2,
} axclrtEngineModelKind;

typedef enum axclrtEngineVNpuKind {
    AXCL_VNPU_DISABLE = 0,
    AXCL_VNPU_ENABLE = 1,
    AXCL_VNPU_BIG_LITTLE = 2,
    AXCL_VNPU_LITTLE_BIG = 3,
} axclrtEngineVNpuKind;

typedef struct axclrtEngineIODims {
    int32_t dimCount;
    int32_t dims[AXCLRT_ENGINE_MAX_DIM_CNT];
} axclrtEngineIODims;

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_ENGINE_TYPE_H__ */
