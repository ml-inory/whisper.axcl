/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AX_AVSCALI_API_H__
#define __AX_AVSCALI_API_H__

#include <string.h>
#include "ax_base_type.h"
#include "ax_avs_api.h"
#include "ax_isp_3a_api.h"

#ifdef __cplusplus
    extern "C" {
#endif

#define AX_AVSCALI_MAX_PATH_LEN    (512)
#define AX_AVSCALI_IP_ADDR_LEN     (15)

/* error code */
#define AX_AVSCALI_SUCC                        (0)
#define AX_ERR_AVSCALI_NULL_PTR                AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_NULL_PTR)
#define AX_ERR_AVSCALI_ILLEGAL_PARAM           AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_ILLEGAL_PARAM)
#define AX_ERR_AVSCALI_NOT_INIT                AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_NOT_INIT)
#define AX_ERR_AVSCALI_FILE_UNEXIST            AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_UNEXIST)
#define AX_ERR_AVSCALI_TIMEOUT                 AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_TIMED_OUT)
#define AX_ERR_AVSCALI_SYS_NOTREADY            AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_SYS_NOTREADY)
#define AX_ERR_AVSCALI_UNKNOWN                 AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_UNKNOWN)
#define AX_ERR_AVSCALI_NOT_SUPPORT             AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_NOT_SUPPORT)
#define AX_ERR_AVSCALI_INITED                  AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_EXIST)
#define AX_ERR_AVSCALI_NOMEM                   AX_DEF_ERR(AX_ID_AVSCALI, 1, AX_ERR_NOMEM)
#define AX_ERR_AVSCALI_CALI_FAIL               AX_DEF_ERR(AX_ID_AVSCALI, 1, 0x80)
#define AX_ERR_AVSCALI_GEO_CALI_FAIL           AX_DEF_ERR(AX_ID_AVSCALI, 1, 0x81)
#define AX_ERR_AVSCALI_DATA_IMCOMPATIBLE       AX_DEF_ERR(AX_ID_AVSCALI, 1, 0x82)
#define AX_ERR_AVSCALI_EMPTY_FILE              AX_DEF_ERR(AX_ID_AVSCALI, 1, 0x83)

typedef struct axAVSCALI_MASK_AREA_INFO_T
{
    AX_U32 nOffsetX;
    AX_U32 nOffsetY;
    AX_U32 nWidth;
    AX_U32 nHeight;
} AX_AVSCALI_MASK_AREA_INFO_T, *AX_AVSCALI_MASK_AREA_INFO_PTR;

typedef struct axAVSCALI_MESH_FILE_INFO_T {
    AX_CHAR strMeshFile[AX_AVS_PIPE_NUM][AX_AVSCALI_MAX_PATH_LEN];
    AX_CHAR strMaskFile[AX_AVS_PIPE_NUM][AX_AVSCALI_MAX_PATH_LEN];
} AX_AVSCALI_MESH_FILES_INFO_T, *AX_AVSCALI_MESH_FILES_INFO_PTR;

typedef struct axAVSCALI_AVS_PARAMS_T
{
    AX_U32                       nOutWidth;
    AX_U32                       nOutHeight;
    AX_AVSCALI_MASK_AREA_INFO_T  tMaskAreaInfo[AX_AVS_PIPE_NUM];
    AX_AVSCALI_MESH_FILES_INFO_T tMeshFileInfo;
    AX_AVS_GRP_CAMERA_PARAM_T    stGrpCameraParam;
} AX_AVSCALI_AVS_PARAMS_T, *AX_AVSCALI_AVS_PARAMS_PTR;

typedef struct axAVSCALI_PIPE_INFO_T {
    AX_U8   nPipeNum;                     // Pipe num
    AX_U8   arrPipeId[AX_AVS_PIPE_NUM];   // Pipe ids: form left to right
    AX_U8   nChn;                         // ISP chn
    AX_BOOL bAroundView;                  // 360-degree view mode
    AX_U32  nImgWidth;                    // Pipe out imgage width
    AX_U32  nImgHeight;                   // Pipe out imgage height
} AX_AVSCALI_PIPE_INFO_T, *AX_AVSCALI_PIPE_INFO_PTR;

typedef struct axAVSCALI_AEAWB_SYNC_RATIO_T
{
    AX_U8 nRatioNum; // AE/AWB sync ratio number. Pass PipeNum for around view mode, or pass (PipeNum - 1): [1, AX_AVS_PIPE_NUM]
    AX_ISP_IQ_AE_SYNC_RATIO_T  tAeSyncRatio[AX_AVS_PIPE_NUM];
    AX_ISP_IQ_AWB_SYNC_RATIO_T tAwbSyncRatio[AX_AVS_PIPE_NUM];
} AX_AVSCALI_AEAWB_SYNC_RATIO_T, *AX_AVSCALI_AEAWB_SYNC_RATIO_PTR;

typedef struct axAVSCALI_CALIDONE_RESULT_T {
    AX_S32                         nResult;
    AX_VOID*                       pPrivData;
} AX_AVSCALI_CALIDONE_RESULT_T, *AX_AVSCALI_CALIDONE_RESULT_PTR;

typedef AX_VOID (*AX_AVSCALI_CaliDone)(const AX_AVSCALI_CALIDONE_RESULT_T* pCaliDoneResult);

typedef struct axAVSCALI_CALLBACK_T
{
    AX_AVSCALI_CaliDone CaliDoneCb;
} AX_AVSCALI_CALLBACK_T, *AX_AVSCALI_CALLBACK_PTR;

typedef struct axAVSCALI_INIT_PARAM_T {
    AX_AVSCALI_PIPE_INFO_T  tPipeInfo;
    AX_AVSCALI_CALLBACK_T   tCallbacks;
    AX_CHAR                 strCaliDataPath[AX_AVSCALI_MAX_PATH_LEN]; // Calibration data save path
    AX_VOID*                pPrivData;
} AX_AVSCALI_INIT_PARAM_T, *AX_AVSCALI_INIT_PARAM_PTR;

typedef struct axAVSCALI_STITCH_OVERLAP_INFO_T
{
    AX_U8 nPipeNum; // Stitch pipe number: [2, AX_AVS_PIPE_NUM]
    AX_ISP_OVERLAP_INFO_T tIspOverlapInfo[AX_AVS_PIPE_NUM][AX_VIN_OVERLAP_NUM];
} AX_AVSCALI_STITCH_OVERLAP_INFO_T, *AX_AVSCALI_STITCH_OVERLAP_INFO_PTR;

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Initialize
///
/// @param pParams  [I]: initialize parameter
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_Init(AX_AVSCALI_INIT_PARAM_T* pParams);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief uninitialize
///
/// @param NA
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_DeInit();

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Start calibrate
///
/// @param pServerIP  [I]: server IP address
/// @param nPort      [I]: server port
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_Start(const AX_CHAR* pServerIP, const AX_U16 nPort);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Stop calibrate
///
/// @param NA
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_Stop();

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Load AVS parameter
///
/// @param pParamPath   [I ]: path of avs parameter data.
///                           If pass nullptr, get current cali avs data after AX_AVSCALI_Init
/// @param pAVSGrpAttr  [IO]: avs group attribution
/// @param pCalibrated  [ O]: whether cali data is calibrated
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_LoadAvsParam(const AX_CHAR* pParamPath, AX_AVS_GRP_ATTR_T* pAVSGrpAttr, AX_BOOL* pCalibrated);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Load AE/AWB sync ratio
///
/// @param pParamPath      [I ]: path of avs parameter data.
///                              If pass nullptr, get current cali ae/awb ratio after AX_AVSCALI_Init
/// @param pAeAwbSyncRatio [IO]: AeAwb sync ratios
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_LoadAeAwbSyncRatio(const AX_CHAR* pParamPath, AX_AVSCALI_AEAWB_SYNC_RATIO_T* pAeAwbSyncRatio);

//////////////////////////////////////////////////////////////////////////////////////
/// @brief Load stitch overlap info
///
/// @param pParamPath         [I ]: path of avs parameter data.
///                                 If pass nullptr, get current stitch overlap info after AX_AVSCALI_Init
/// @param pStitchOverlapInfo [IO]: stitch overlap info
///
/// @return 0 if success, otherwise failure
//////////////////////////////////////////////////////////////////////////////////////
AX_S32 AX_AVSCALI_LoadStitchOverlayInfo(const AX_CHAR* pParamPath, AX_AVSCALI_STITCH_OVERLAP_INFO_T* pStitchOverlapInfo);
#ifdef __cplusplus
}
#endif

#endif