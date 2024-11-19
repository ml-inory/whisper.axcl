/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AXCL_SYS_API_H__
#define __AXCL_SYS_API_H__

#include "axcl_sys_type.h"

#ifdef __cplusplus
extern "C" {
#endif

AX_S32 AXCL_SYS_Init(AX_VOID);
AX_S32 AXCL_SYS_Deinit(AX_VOID);

/* CMM API */
AX_S32 AXCL_SYS_MemAlloc(AX_U64 *phyaddr, AX_VOID **pviraddr, AX_U32 size, AX_U32 align, const AX_S8 *token);
AX_S32 AXCL_SYS_MemAllocCached(AX_U64 *phyaddr, AX_VOID **pviraddr, AX_U32 size, AX_U32 align, const AX_S8 *token);
AX_S32 AXCL_SYS_MemFree(AX_U64 phyaddr, AX_VOID *pviraddr);
AX_VOID *AXCL_SYS_Mmap(AX_U64 phyaddr, AX_U32 size);
AX_VOID *AXCL_SYS_MmapCache(AX_U64 phyaddr, AX_U32 size);
AX_VOID *AXCL_SYS_MmapFast(AX_U64 phyaddr, AX_U32 size);
AX_VOID *AXCL_SYS_MmapCacheFast(AX_U64 phyaddr, AX_U32 size);
AX_S32 AXCL_SYS_Munmap(AX_VOID *pviraddr, AX_U32 size);
AX_S32 AXCL_SYS_MflushCache(AX_U64 phyaddr, AX_VOID *pviraddr, AX_U32 size);
AX_S32 AXCL_SYS_MinvalidateCache(AX_U64 phyaddr, AX_VOID *pviraddr, AX_U32 size);
AX_S32 AXCL_SYS_MemGetBlockInfoByPhy(AX_U64 phyaddr, AX_S32 *pmemType, AX_VOID **pviraddr, AX_U32 *pblockSize);
AX_S32 AXCL_SYS_MemGetBlockInfoByVirt(AX_VOID *pviraddr, AX_U64 *phyaddr, AX_S32 *pmemType);
AX_S32 AXCL_SYS_MemGetPartitionInfo(AX_CMM_PARTITION_INFO_T *pCmmPartitionInfo);
AX_S32 AXCL_SYS_MemSetConfig(const AX_MOD_INFO_T *pModInfo, const AX_S8 *pPartitionName);
AX_S32 AXCL_SYS_MemGetConfig(const AX_MOD_INFO_T *pModInfo, AX_S8 *pPartitionName);
AX_S32 AXCL_SYS_MemQueryStatus(AX_CMM_STATUS_T *pCmmStatus);

/* LINK API*/
AX_S32 AXCL_SYS_Link(const AX_MOD_INFO_T *pSrc, const AX_MOD_INFO_T *pDest);
AX_S32 AXCL_SYS_UnLink(const AX_MOD_INFO_T *pSrc, const AX_MOD_INFO_T *pDest);
AX_S32 AXCL_SYS_GetLinkByDest(const AX_MOD_INFO_T *pDest, AX_MOD_INFO_T *pSrc);
AX_S32 AXCL_SYS_GetLinkBySrc(const AX_MOD_INFO_T *pSrc, AX_LINK_DEST_T *pLinkDest);

/* POOL API */
AX_S32 AXCL_POOL_SetConfig(const AX_POOL_FLOORPLAN_T *pPoolFloorPlan);
AX_S32 AXCL_POOL_GetConfig(AX_POOL_FLOORPLAN_T *pPoolFloorPlan);
AX_S32 AXCL_POOL_Init(AX_VOID);
AX_S32 AXCL_POOL_Exit(AX_VOID);
AX_POOL AXCL_POOL_CreatePool(AX_POOL_CONFIG_T *pPoolConfig);
AX_S32 AXCL_POOL_DestroyPool(AX_POOL PoolId);
AX_BLK AXCL_POOL_GetBlock(AX_POOL PoolId, AX_U64 BlkSize, const AX_S8 *pPartitionName);
AX_S32 AXCL_POOL_ReleaseBlock(AX_BLK BlockId);
AX_BLK AXCL_POOL_PhysAddr2Handle(AX_U64 PhysAddr);
AX_U64 AXCL_POOL_Handle2PhysAddr(AX_BLK BlockId);
AX_U64 AXCL_POOL_Handle2MetaPhysAddr(AX_BLK BlockId);
AX_POOL AXCL_POOL_Handle2PoolId(AX_BLK BlockId);
AX_U64 AXCL_POOL_Handle2BlkSize(AX_BLK BlockId);
AX_S32 AXCL_POOL_MmapPool(AX_POOL PoolId);
AX_S32 AXCL_POOL_MunmapPool(AX_POOL PoolId);
AX_VOID *AXCL_POOL_GetBlockVirAddr(AX_BLK BlockId);
AX_VOID *AXCL_POOL_GetMetaVirAddr(AX_BLK BlockId);
AX_S32 AXCL_POOL_IncreaseRefCnt(AX_BLK BlockId);
AX_S32 AXCL_POOL_DecreaseRefCnt(AX_BLK BlockId);

/* PTS API */
AX_S32 AXCL_SYS_GetCurPTS(AX_U64 *pu64CurPTS);
AX_S32 AXCL_SYS_InitPTSBase(AX_U64 u64PTSBase);
AX_S32 AXCL_SYS_SyncPTS(AX_U64 u64PTSBase);

/* GET CHIP TYPE API */
AX_CHIP_TYPE_E AXCL_SYS_GetChipType(AX_VOID);

/* LOG API */
AX_S32 AXCL_SYS_SetLogLevel(AX_LOG_LEVEL_E target);
AX_S32 AXCL_SYS_SetLogTarget(AX_LOG_TARGET_E target);
AX_S32 AXCL_SYS_EnableTimestamp(AX_BOOL enable);

/* PM API */
AX_S32 AXCL_SYS_Sleep(AX_VOID);
AX_S32 AXCL_SYS_WakeLock(const AX_MOD_ID_E ModId);
AX_S32 AXCL_SYS_WakeUnlock(const AX_MOD_ID_E ModId);
AX_S32 AXCL_SYS_RegisterEventCb(const AX_MOD_ID_E ModId, NotifyEventCallback pFunction, AX_VOID *pData);
AX_S32 AXCL_SYS_UnregisterEventCb(const AX_MOD_ID_E ModId);

#ifdef __cplusplus
}
#endif

#endif /* __EXTERNAL_AXCL_MM_SYS_H__ */