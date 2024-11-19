/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_BASE_H__
#define __AXCL_BASE_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__)
#define AXCL_EXPORT __attribute((visibility("default")))
#elif defined(_MSC_VER)
#define AXCL_EXPORT __declspec(dllexport)
#else
#define AXCL_EXPORT
#endif

#ifdef __GNUC__
#define AXCL_DEPRECATED __attribute__((deprecated))
#define AXCL_DEPRECATED_MESSAGE(message) __attribute__((deprecated(message)))
#elif defined(_MSC_VER)
#define AXCL_DEPRECATED __declspec(deprecated)
#define AXCL_DEPRECATED_MESSAGE(message) __declspec(deprecated(message))
#else
#define AXCL_DEPRECATED
#define AXCL_DEPRECATED_MESSAGE(message)
#endif

#define NO_TIMEOUT (-1)
#define AXCL_MAX_DEVICE_COUNT (256)

typedef int32_t axclError;
typedef void *axclrtContext;
typedef void *axclrtStream;

typedef enum {
    AXCL_SUCC                   = 0x00,
    AXCL_FAIL                   = 0x01,
    AXCL_ERR_UNKNOWN            = AXCL_FAIL,
    AXCL_ERR_NULL_POINTER       = 0x02,
    AXCL_ERR_ILLEGAL_PARAM      = 0x03,
    AXCL_ERR_UNSUPPORT          = 0x04,
    AXCL_ERR_TIMEOUT            = 0x05,
    AXCL_ERR_BUSY               = 0x06,
    AXCL_ERR_NO_MEMORY          = 0x07,
    AXCL_ERR_ENCODE             = 0x08,
    AXCL_ERR_DECODE             = 0x09,
    AXCL_ERR_UNEXPECT_RESPONSE  = 0x0A,
    AXCL_ERR_OPEN               = 0x0B,
    AXCL_ERR_EXECUTE_FAIL       = 0x0C,

    AXCL_ERR_BUTT               = 0x7F
} AXCL_ERROR_E;

#define AX_ID_AXCL           (0x30)

/* module */
#define AXCL_RUNTIME         (0x00)
#define AXCL_NATIVE          (0x01)

/* runtime sub module */
#define AXCL_RUNTIME_DEVICE  (0x01)
#define AXCL_RUNTIME_CONTEXT (0x02)
#define AXCL_RUNTIME_STREAM  (0x03)
#define AXCL_RUNTIME_TASK    (0x04)
#define AXCL_RUNTIME_MEMORY  (0x05)
#define AXCL_RUNTIME_CONFIG  (0x06)
#define AXCL_RUNTIME_ENGINE  (0x07)

/**
 * |---------------------------------------------------------|
 * | |   MODULE    |  AX_ID_AXCL | SUB_MODULE  |    ERR_ID   |
 * |1|--- 7bits ---|--- 8bits ---|--- 8bits ---|--- 8bits ---|
 **/
#define AXCL_DEF_ERR(module, sub, errid) \
    ((axclError)((0x80000000L) | (((module) & 0x7F) << 24) | ((AX_ID_AXCL) << 16 ) | ((sub) << 8) | (errid)))

#define AXCL_DEF_RUNTIME_ERR(sub, errid)    AXCL_DEF_ERR(AXCL_RUNTIME, (sub), (errid))
#define AXCL_DEF_NATIVE_ERR(sub,  errid)    AXCL_DEF_ERR(AXCL_NATIVE,  (sub), (errid))

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_BASE_H__ */