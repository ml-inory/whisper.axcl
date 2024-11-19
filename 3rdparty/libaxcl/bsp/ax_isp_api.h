/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef __AX_ISP_API_H__
#define __AX_ISP_API_H__

#include "ax_base_type.h"
#include "ax_global_type.h"
#include "ax_isp_common.h"
#include "ax_isp_iq_api.h"
#include "ax_isp_version.h"
#include "ax_sensor_struct.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
    AX_IRQ_TYPE_FRAME_DONE      = 0,
    AX_IRQ_TYPE_IFE_AF_DONE     = 1,
    AX_IRQ_TYPE_ITP_AF_DONE     = 2,
} AX_IRQ_TYPE_E;

typedef enum {
    AX_ISP_CTRL_SLEEP,
    AX_ISP_CTRL_WAKE_UP,
    AX_ISP_CTRL_IMAGE_MODE_SET,
    AX_ISP_CTRL_AE_FPS_BASE_SET,
    AX_ISP_CTRL_EXP_INFO_SYNC,
    AX_ISP_CTRL_PROC_WRITE,
    AX_ISP_CTRL_MAX,
} AX_ISP_CTRL_CMD_E;


/**********************************************************************************
 *                                   AE
 * input (AX_ISP_AE_INPUT_INFO_T) --> ae_alg --> output (AX_ISP_AE_RESULT_T)
 **********************************************************************************/
#define AX_HDR_RATIO_CHN_NUM (3)

typedef enum {
    AX_HDR_RATIO_CHN_L_M = 0,   /* long frame / middle frame */
    AX_HDR_RATIO_CHN_M_S,       /* middle frame / short frame */
    AX_HDR_RATIO_CHN_S_VS,      /* short frame / very short frame */
} AX_HDR_RATIO_CHN_E;

typedef struct _AX_ISP_STITICH_PIPE_ATTR_T_ {
    AX_U8                   nPipeId;
    AX_U8                   bMirrorFlip;
    AX_ISP_OVERLAP_INFO_T   tOverlapInfo[AX_VIN_OVERLAP_NUM];
} AX_ISP_STITICH_PIPE_ATTR_T;

typedef struct _AX_ISP_STITCH_GRP_ATTR_T_ {
    AX_U8                       bStitchEn;
    AX_U8                       bAroundView;
    AX_U8                       nMainPipeId;
    AX_U8                       nStitchPipeNum;
    AX_ISP_STITICH_PIPE_ATTR_T  tStitchPipeAttr[AX_VIN_STITCH_MAX_PIPE_NUM];
} AX_ISP_STITCH_GRP_ATTR_T;

typedef struct {
    AX_U8 bHistWeightUpdate;                                                  /* AX_TRUE : use AX_ISP_AE_RESULT_T nHistWeight AX_FALSE : use AX_ISP_IQ_AE_STAT_PARAM_T nHistWeight*/
    AX_U8 nHistWeight[AX_AE_HIST_WEIGHT_BLK_ROW * AX_AE_HIST_WEIGHT_BLK_COL]; /* Hist Weight, Accuracy: U8.0, Range: [0, 255], 16 x 16 block */
} AX_ISP_AE_STAT_ATTR_T;

typedef struct {
    AX_U32                      nSnsId;
    AX_SNS_HDR_MODE_E           eSnsMode;
    AX_BAYER_PATTERN_E          eBayerPattern;
    AX_U32                      nFrameRate;
    AX_ISP_STITCH_GRP_ATTR_T    tStitchAttr;
} AX_ISP_AE_INITATTR_T;

typedef struct _AX_ISP_AE_STAT_ADJACENT_T_ {
    AX_U8                   nPipeId;
    AX_BOOL                 nValid;
    AX_ISP_AE_STAT_INFO_T   *tStat;
} AX_ISP_AE_STAT_ADJACENT_T;

typedef struct _AX_ISP_AE_STITCH_STAT_T_ {
    AX_ISP_AE_STAT_ADJACENT_T tAdjacentStats[AX_VIN_STITCH_MAX_PIPE_NUM];
} AX_ISP_AE_STITCH_STAT_T;

typedef struct _AX_ISP_AE_INPUT_INFO_T_ {
    AX_ISP_AE_STAT_INFO_T    tAeStat;
    AX_ISP_AE_STITCH_STAT_T  tAeStitchStat;
} AX_ISP_AE_INPUT_INFO_T;

typedef struct _AX_ISP_AE_RESULT_T_ {
    AX_U32 nIntTime[AX_HDR_CHN_NUM];            /* ExposeTime(us). Accuracy: U32 Range: [0x0, 0xFFFFFFFF] */

    AX_U32 nAgain[AX_HDR_CHN_NUM];              /* Total Again value. Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF]
                                                 * Total Again = Sensor Register Again x HCG Ratio
                                                 * LCG Mode: HCG Ratio = 1.0
                                                 * HCG Mode: HCG Ratio = Refer to Sensor Spec */

    AX_U32 nDgain[AX_HDR_CHN_NUM];              /* Sensor Dgain value. Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF]
                                                 * Not Used, should be set to 0x400. AX Platform Use ISP DGain */

    AX_U32 nIspGain;                            /* ISP Dgain value. Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF] */

    AX_U32 nTotalGain[AX_HDR_CHN_NUM];          /* Total Gain value. Accuracy: U22.10 Range: [0x400, 0xFFFFFFFF]
                                                 * Total Gain value = SensorRegisterAgain * SensorDgain * CurrHcgRatio * IspGain */

    AX_U8  nHcgLcgMode;                         /* 0:HCG 1:LCG 2:Not Support */

    AX_U32 nHcgLcgRatio;                        /* Accuracy: U10.10 Range: [0x400, 0x2800] */

    AX_U32 nHdrRatio[AX_HDR_RATIO_CHN_NUM];     /* Accuracy: U7.10 Range: [0x400, 0x1FC00] */

    AX_U32 nLux;                                /* Accuracy: U22.10 Range: [0, 0xFFFFFFFF]
                                                 * fLux = (MeanLuma*LuxK) / (AGain*Dgain*IspGain)
                                                 * where LuxK is a calibrated factor */

    AX_U32 nMeanLuma;                           /* Mean Luma of the Frame. Accuracy: U8.10 Range:[0, 0x3FC00] */

    // AX_BOOL bNeedExcu;                       /* true:need caller to config sensor */
    AX_U8 nAeStable;                            /* 0:AE Not Stabled; 1:AE Stabled */
    AX_ISP_LFHDR_MODE_E   eLFHdrMode;           /* long frame mode */
    AX_ISP_AE_STAT_ATTR_T tAeStatAttr;

    //dynamic range
    AX_U32 nDynamicRange;                       /* Accuracy: U8.10 Range: [0x400, 0x3FC00] */
    AX_U8 nAeOutPutHdrMode;                     /* 0:AX_SNS_LINEAR_MODE; 1:AX_SNS_HDR_2X_MODE */
    AX_U32 nLinePeriod;                         /* LinePeriodTime(us). Accuracy: U32 Range: [0x0, 0xFFFFFFFF] */
} AX_ISP_AE_RESULT_T;

typedef struct _AX_ISP_AE_REGFUNCS_T_ {
    AX_S32(*pfnAe_Init)(AX_U8 nPipeId, AX_ISP_AE_INITATTR_T *pAeInitParam, AX_ISP_AE_RESULT_T *pAeResult);
    AX_S32(*pfnAe_Run)(AX_U8 nPipeId, AX_ISP_AE_INPUT_INFO_T *pAeInputInfo, AX_ISP_AE_RESULT_T *pAeResult);
    AX_S32(*pfnAe_Exit)(AX_U8 nPipeId);
    AX_S32(*pfnAe_Ctrl)(AX_U8 nPipeId, AX_ISP_CTRL_CMD_E eAeCtrlCmd, AX_ISP_AE_RESULT_T *pAeResult, AX_VOID *pValue);
} AX_ISP_AE_REGFUNCS_T;


/**********************************************************************************
 *                                  AWB
 * input (AX_ISP_AWB_INPUT_INFO_T) --> awb_alg --> output (AX_ISP_AWB_RESULT_T)
 **********************************************************************************/
typedef struct _AX_ISP_AWB_INITATTR_T_ {
    AX_U32                      nSnsId;
    AX_SNS_HDR_MODE_E           eSnsMode;
    AX_BAYER_PATTERN_E          eBayerPattern;
    AX_U32                      nFrameRate;
    AX_ISP_STITCH_GRP_ATTR_T    tStitchAttr;
} AX_ISP_AWB_INITATTR_T;

typedef struct _AX_ISP_AWB_STAT_ADJACENT_T_ {
    AX_U8                   nPipeId;
    AX_BOOL                 nValid;
    AX_ISP_AWB_STAT_INFO_T  *tStat;
} AX_ISP_AWB_STAT_ADJACENT_T;

typedef struct _AX_ISP_AWB_STITCH_STAT_T_ {
    AX_ISP_AWB_STAT_ADJACENT_T tAdjacentStat[AX_VIN_STITCH_MAX_PIPE_NUM];
} AX_ISP_AWB_STITCH_STAT_T;

typedef struct _AX_ISP_AWB_INPUT_INFO_T_ {
    AX_U32                      nLux;        /* from AE */
    AX_U32                      nMeanLuma;   /* from AE */
    AX_ISP_AWB_STAT_INFO_T      tAwbStat;
    AX_ISP_AWB_STITCH_STAT_T    tAwbStitchStat;
} AX_ISP_AWB_INPUT_INFO_T;

typedef struct _AX_ISP_AWB_RESULT_T_ {
    AX_U16 nGrGain;         /* = gain * 256.0f, gain:[1.00f, 15.9960938f] Accuracy:U4.8 Range:[256, 4095] */
    AX_U16 nGbGain;         /* = gain * 256.0f, gain:[1.00f, 15.9960938f] Accuracy:U4.8 Range:[256, 4095] */
    AX_U16 nRgain;          /* = gain * 256.0f, gain:[1.00f, 15.9960938f] Accuracy:U4.8 Range:[256, 4095] */
    AX_U16 nBgain;          /* = gain * 256.0f, gain:[1.00f, 15.9960938f] Accuracy:U4.8 Range:[256, 4095] */
    AX_U16 nColorTemp;      /* Accuracy:U14 Range:[0, 16000]  Color Temperature */
    AX_U8  nSatDiscnt;      /* Saturation Used for CCM or LSC Interpolation,  Accuracy:U8 Range:[0, 100] Current Saturation Discount
                             * e.g. 100 for 100%
                             * If Not Used, Just return 100 */
} AX_ISP_AWB_RESULT_T;

typedef struct _AX_ISP_AWB_REGFUNCS_T_ {
    AX_S32(*pfnAwb_Init)(AX_U8 nPipeId, AX_ISP_AWB_INITATTR_T *pAwbInitParam, AX_ISP_AWB_RESULT_T *pAwbResult);
    AX_S32(*pfnAwb_Run)(AX_U8 nPipeId, AX_ISP_AWB_INPUT_INFO_T *pAwbInputInfo, AX_ISP_AWB_RESULT_T *pAwbResult);
    AX_S32(*pfnAwb_Exit)(AX_U8 nPipeId);
} AX_ISP_AWB_REGFUNCS_T;

/**********************************************************************************
 *                                  AF
 **********************************************************************************/

typedef struct _AX_ISP_AF_REGFUNCS_T_ {
    AX_S32(*pfnCAf_Init)(AX_U8 nPipeId);
    AX_S32(*pfnCAf_Run)(AX_U8 nPipeId);
    AX_S32(*pfnCAf_Exit)(AX_U8 nPipeId);
} AX_ISP_AF_REGFUNCS_T;

typedef struct _AX_ISP_PUB_ATTR_T_ {
    AX_U16 nSnsDefaultBlackLevel;
} AX_ISP_PUB_ATTR_T;

typedef enum {
    AX_ISP_DEPEND_PIPE_NONE     = 0,
    AX_ISP_DEPEND_PIPE_MODE0    = 1,
} AX_ISP_DEPEND_PIPE_MODE_E;

typedef struct _AX_ISP_DEPEND_ATTR_T_ {
    AX_U32                      nDependPipeId;  /* nDependPipeId is used to specify which pipe to share information from */
    AX_ISP_DEPEND_PIPE_MODE_E   eDependMode;
} AX_ISP_DEPEND_ATTR_T;

typedef struct _AX_ISP_THREAD_SCHED_T_ {
    AX_U32 nPolicy;           /* 0:SCHED_OTHER, 1:SCHED_FIFO, 2:SCHED_RR */
    AX_U32 nPriority;         /* SCHED_OTHER:[0], SCHED_FIFO&SCHED_RR:[1,99] */
} AX_ISP_THREAD_SCHED_T;

typedef struct _AX_ISP_VERSION_T_ {
    AX_U32  nIspMajor;
    AX_U32  nIspMinor1;
    AX_U32  nIspMinor2;
    AX_CHAR szBuildTime[AX_ISP_BUILD_TIME_MAX_SIZE];
    AX_CHAR szIspVersion[AX_ISP_VERSION_MAX_SIZE];
} AX_ISP_VERSION_T;


/************************************************************************************
 *  SENSOR API
 ************************************************************************************/
AX_S32 AX_ISP_RegisterSensor(AX_U8 nPipeId, AX_SENSOR_REGISTER_FUNC_T *ptSnsRegister);
AX_S32 AX_ISP_UnRegisterSensor(AX_U8 nPipeId);

AX_S32 AX_ISP_SetSnsAttr(AX_U8 nPipeId, AX_SNS_ATTR_T *pSnsAttr);
AX_S32 AX_ISP_GetSnsAttr(AX_U8 nPipeId, AX_SNS_ATTR_T *pSnsAttr);

AX_S32 AX_ISP_OpenSnsClk(AX_U8 nClkIdx, AX_SNS_CLK_RATE_E eClkRate);
AX_S32 AX_ISP_CloseSnsClk(AX_U8 nClkIdx);

AX_S32 AX_ISP_StreamOn(AX_U8 nPipeId);
AX_S32 AX_ISP_StreamOff(AX_U8 nPipeId);

AX_S32 AX_ISP_SetSnsFuncMask(AX_U8 nPipeId, AX_SNS_FUNC_MASK_T *ptFuncMask);
AX_S32 AX_ISP_GetSnsFuncMask(AX_U8 nPipeId, AX_SNS_FUNC_MASK_T *ptFuncMask);

AX_S32 AX_ISP_FflushSensor(AX_U8 nPipeId);


/************************************************************************************
 *  ISP API
 ************************************************************************************/
AX_S32 AX_ISP_RegisterAeLibCallback(AX_U8 nPipeId, AX_ISP_AE_REGFUNCS_T *ptRegister);
AX_S32 AX_ISP_UnRegisterAeLibCallback(AX_U8 nPipeId);

AX_S32 AX_ISP_RegisterAwbLibCallback(AX_U8 nPipeId, AX_ISP_AWB_REGFUNCS_T *ptRegister);
AX_S32 AX_ISP_UnRegisterAwbLibCallback(AX_U8 nPipeId);

AX_S32 AX_ISP_RegisterLscLibCallback(AX_U8 nPipeId, void *ptRegister);
AX_S32 AX_ISP_UnRegisterLscLibCallback(AX_U8 nPipeId);

AX_S32 AX_ISP_LoadBinParams(AX_U8 nPipeId, const AX_CHAR *pFileName);

AX_S32 AX_ISP_Create(AX_U8 nPipeId);
AX_S32 AX_ISP_Destroy(AX_U8 nPipeId);

AX_S32 AX_ISP_Open(AX_U8 nPipeId);
AX_S32 AX_ISP_Close(AX_U8 nPipeId);

AX_S32 AX_ISP_Start(AX_U8 nPipeId);
AX_S32 AX_ISP_Stop(AX_U8 nPipeId);

AX_S32 AX_ISP_RunOnce(AX_U8 nPipeId);

AX_S32 AX_ISP_GetIrqTimeOut(AX_U8 nPipeId, AX_IRQ_TYPE_E eIrqType, AX_S32 nTimeOutMs);

AX_S32 AX_ISP_SetPubAttr(AX_U8 nPipeId, const AX_ISP_PUB_ATTR_T *ptIspPubAttr);
AX_S32 AX_ISP_GetPubAttr(AX_U8 nPipeId, AX_ISP_PUB_ATTR_T *ptIspPubAttr);
AX_S32 AX_ISP_GetVersion(AX_ISP_VERSION_T *ptIspVersion);

AX_S32 AX_ISP_SetDependAttr(AX_U8 nPipeId, const AX_ISP_DEPEND_ATTR_T *ptIspDependAttr);
AX_S32 AX_ISP_GetDependAttr(AX_U8 nPipeId, AX_ISP_DEPEND_ATTR_T *ptIspDependAttr);

AX_S32 AX_ISP_SetThreadSched(AX_U8 nPipeId, const AX_ISP_THREAD_SCHED_T *pSched);
AX_S32 AX_ISP_GetThreadSched(AX_U8 nPipeId, AX_ISP_THREAD_SCHED_T *pSched);

#ifdef __cplusplus
}
#endif

#endif  //_AX_ISP_API_H_
