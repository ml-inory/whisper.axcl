/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_ENGINE_API_H__
#define __AXCL_ENGINE_API_H__

#include "axcl_npu_type.h"

#ifdef __cplusplus
extern "C" {
#endif

const AX_CHAR* AXCL_ENGINE_GetVersion(AX_VOID);

AX_VOID AXCL_ENGINE_NPUReset(AX_VOID);

AX_S32 AXCL_ENGINE_Init(AX_ENGINE_NPU_ATTR_T* pNpuAttr);
AX_S32 AXCL_ENGINE_GetVNPUAttr(AX_ENGINE_NPU_ATTR_T* pNpuAttr);
AX_S32 AXCL_ENGINE_Deinit(AX_VOID);

AX_S32 AXCL_ENGINE_GetModelType(const AX_VOID* pData, AX_U32 nDataSize, AX_ENGINE_MODEL_TYPE_T* pModelType);

AX_S32 AXCL_ENGINE_CreateHandle(AX_ENGINE_HANDLE* pHandle, const AX_VOID* pData, AX_U32 nDataSize);
AX_S32 AXCL_ENGINE_CreateHandleV2(AX_ENGINE_HANDLE* pHandle, const AX_VOID* pData, AX_U32 nDataSize, AX_ENGINE_HANDLE_EXTRA_T* pExtraParam);
AX_S32 AXCL_ENGINE_DestroyHandle(AX_ENGINE_HANDLE nHandle);

AX_S32 AXCL_ENGINE_GetIOInfo(AX_ENGINE_HANDLE nHandle, AX_ENGINE_IO_INFO_T** pIO);
AX_S32 AXCL_ENGINE_GetGroupIOInfoCount(AX_ENGINE_HANDLE nHandle, AX_U32* pCount);
AX_S32 AXCL_ENGINE_GetGroupIOInfo(AX_ENGINE_HANDLE nHandle, AX_U32 nIndex, AX_ENGINE_IO_INFO_T** pIO);

AX_S32 AXCL_ENGINE_GetHandleModelType(AX_ENGINE_HANDLE nHandle, AX_ENGINE_MODEL_TYPE_T* pModelType);

AX_S32 AXCL_ENGINE_CreateContext(AX_ENGINE_HANDLE handle);
AX_S32 AXCL_ENGINE_CreateContextV2(AX_ENGINE_HANDLE nHandle, AX_ENGINE_CONTEXT_T* pContext);

AX_S32 AXCL_ENGINE_RunSync(AX_ENGINE_HANDLE handle, AX_ENGINE_IO_T* pIO);
AX_S32 AXCL_ENGINE_RunSyncV2(AX_ENGINE_HANDLE handle, AX_ENGINE_CONTEXT_T context, AX_ENGINE_IO_T* pIO);
AX_S32 AXCL_ENGINE_RunGroupIOSync(AX_ENGINE_HANDLE handle, AX_ENGINE_CONTEXT_T context, AX_U32 nIndex, AX_ENGINE_IO_T* pIO);

AX_S32 AXCL_ENGINE_SetAffinity(AX_ENGINE_HANDLE nHandle, AX_ENGINE_NPU_SET_T nNpuSet);
AX_S32 AXCL_ENGINE_GetAffinity(AX_ENGINE_HANDLE nHandle, AX_ENGINE_NPU_SET_T* pNpuSet);

AX_S32 AXCL_ENGINE_GetCMMUsage(AX_ENGINE_HANDLE nHandle, AX_ENGINE_CMM_INFO* pCMMInfo);

const AX_CHAR* AXCL_ENGINE_GetModelToolsVersion(AX_ENGINE_HANDLE nHandle);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_ENGINE_API_H__ */