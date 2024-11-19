/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_H__
#define __AXCL_H__

#include "axcl_base.h"
#include "axcl_native.h"
#include "axcl_rt.h"

#ifdef __cplusplus
extern "C" {
#endif

axclError axclInit(const char *config);
axclError axclFinalize();

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_H__ */