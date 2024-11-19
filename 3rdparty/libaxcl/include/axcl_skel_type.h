/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef _AXCL_SKEL_TYPE_H_
#define _AXCL_SKEL_TYPE_H_

#include "axcl_base.h"
#include "ax_global_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* error code */
#define AXCL_SKEL_SUCC                        (0)
#define AXCL_ERR_SKEL_NULL_PTR                AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_NULL_PTR)
#define AXCL_ERR_SKEL_ILLEGAL_PARAM           AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_ILLEGAL_PARAM)
#define AXCL_ERR_SKEL_NOT_INIT                AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_NOT_INIT)
#define AXCL_ERR_SKEL_QUEUE_EMPTY             AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_QUEUE_EMPTY)
#define AXCL_ERR_SKEL_QUEUE_FULL              AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_QUEUE_FULL)
#define AXCL_ERR_SKEL_UNEXIST                 AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_UNEXIST)
#define AXCL_ERR_SKEL_TIMEOUT                 AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_TIMED_OUT)
#define AXCL_ERR_SKEL_SYS_NOTREADY            AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_SYS_NOTREADY)
#define AXCL_ERR_SKEL_INVALID_HANDLE          AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_INVALID_CHNID)
#define AXCL_ERR_SKEL_NOMEM                   AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_NOMEM)
#define AXCL_ERR_SKEL_UNKNOWN                 AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_UNKNOWN)
#define AXCL_ERR_SKEL_NOT_SUPPORT             AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_NOT_SUPPORT)
#define AXCL_ERR_SKEL_INITED                  AX_DEF_ERR(AX_ID_SKEL, 1, AX_ERR_EXIST)


/// @brief pipeline type
typedef enum axclSKEL_PPL_E {
    AXCL_SKEL_PPL_HVCP = 1,              /* hvcfp detection pipeline */
    AXCL_SKEL_PPL_FACE = 2,              /* face feature detection pipeline */
    AXCL_SKEL_PPL_MAX,
} AXCL_SKEL_PPL_E;

/// @brief npu type
typedef enum axclSKEL_NPU_TYPE_E {
    AXCL_SKEL_NPU_DEFAULT = 0,        /* running under default NPU according to system */
    AXCL_SKEL_STD_VNPU_1 = (1 << 0),  /* running under STD VNPU1 */
    AXCL_SKEL_STD_VNPU_2 = (1 << 1),  /* running under STD VNPU2 */
    AXCL_SKEL_STD_VNPU_3 = (1 << 2),  /* running under STD VNPU3 */
    AXCL_SKEL_BL_VNPU_1 = (1 << 3),   /* running under BIG-LITTLE VNPU1 */
    AXCL_SKEL_BL_VNPU_2 = (1 << 4)    /* running under BIG-LITTLE VNPU2 */
} AXCL_SKEL_NPU_TYPE_E;

/// @brief init parameter struct
typedef struct axclSKEL_INIT_PARAM_T {
    AX_S32 nDeviceId;
    const AX_CHAR *pStrModelDeploymentPath;
} AXCL_SKEL_INIT_PARAM_T;

/// @brief rect struct
typedef struct axclSKEL_RECT_T {
    AX_F32 fX;
    AX_F32 fY;
    AX_F32 fW;
    AX_F32 fH;
} AXCL_SKEL_RECT_T;

/// @brief point struct
typedef struct axclSKEL_POINT_T {
    AX_F32 fX;
    AX_F32 fY;
} AXCL_SKEL_POINT_T;

/// @brief point set struct
typedef struct axclSKEL_POINT_SET_T {
    const AX_CHAR *pstrObjectCategory;
    AXCL_SKEL_POINT_T stPoint;
    AX_F32 fConfidence;
} AXCL_SKEL_POINT_SET_T;

/// @brief meta info struct
typedef struct axclSKEL_META_INFO_T {
    AX_CHAR *pstrType;
    AX_CHAR *pstrValue;
} AXCL_SKEL_META_INFO_T;

/// @brief config item struct
typedef struct axclSKEL_CONFIG_ITEM_T {
    AX_CHAR *pstrType;
    AX_VOID *pstrValue;
    AX_U32 nValueSize;
} AXCL_SKEL_CONFIG_ITEM_T;

/// @brief config struct
typedef struct axclSKEL_CONFIG_T {
    AX_U32 nSize;
    AXCL_SKEL_CONFIG_ITEM_T *pstItems;
} AXCL_SKEL_CONFIG_T;

/// @brief handle parameter struct
typedef struct axclSKEL_HANDLE_PARAM_T {
    AXCL_SKEL_PPL_E ePPL;
    AX_U32 nWidth;
    AX_U32 nHeight;
    AX_U32 nFrameDepth;
    AX_U32 nFrameCacheDepth;
    AX_U32 nIoDepth;
    AX_U32 nNpuType;
    AXCL_SKEL_CONFIG_T stConfig;
} AXCL_SKEL_HANDLE_PARAM_T;

/// @brief feature item struct
typedef struct axclSKEL_FEATURE_ITEM_T {
    AX_CHAR *pstrType;
    AX_VOID *pstrValue;
    AX_U32 nValueSize;
} AXCL_SKEL_FEATURE_ITEM_T;

/// @brief tract status
typedef enum axclSKEL_TRACK_STATUS_E {
    AXCL_SKEL_TRACK_STATUS_NEW,
    AXCL_SKEL_TRACK_STATUS_UPDATE,
    AXCL_SKEL_TRACK_STATUS_DIE,
    AXCL_SKEL_TRACK_STATUS_SELECT,
    AXCL_SKEL_TRACK_STATUS_MAX,
} AXCL_SKEL_TRACK_STATUS_E;

/// @brief crop frame struct
typedef struct axclSKEL_CROP_FRAME_T {
    AX_U64 nFrameId;
    AX_U8 *pFrameData;
    AX_U32 nFrameDataSize;
    AX_U32 nFrameWidth;
    AX_U32 nFrameHeight;
} AXCL_SKEL_CROP_FRAME_T;

/// @brief pose blur config
typedef struct axclSKEL_POSE_BLUR_T {
    AX_F32 fPitch;
    AX_F32 fYaw;
    AX_F32 fRoll;
    AX_F32 fBlur; // 0 - 1
} AXCL_SKEL_POSE_BLUR_T;

/// @brief object item struct
typedef struct axclSKEL_OBJECT_ITEM_T {
    const AX_CHAR *pstrObjectCategory;
    AXCL_SKEL_RECT_T stRect;
    AX_U64 nFrameId;
    AX_U64 nTrackId;
    AXCL_SKEL_TRACK_STATUS_E eTrackState;
    AX_F32 fConfidence;
    AXCL_SKEL_POSE_BLUR_T stFacePostBlur;
    AX_BOOL bCropFrame;
    AXCL_SKEL_CROP_FRAME_T stCropFrame;
    AX_BOOL bPanoraFrame;
    AXCL_SKEL_CROP_FRAME_T stPanoraFrame;
    AX_U8 nPointSetSize;
    AXCL_SKEL_POINT_SET_T *pstPointSet;
    AX_U8 nFeatureSize;
    AXCL_SKEL_FEATURE_ITEM_T *pstFeatureItem;
    AX_U32 nMetaInfoSize;
    AXCL_SKEL_META_INFO_T *pstMetaInfo;
} AXCL_SKEL_OBJECT_ITEM_T;

typedef struct axclSKEL_FRAME_CACHE_LIST_T {
    AX_U64 nFrameId;
    AX_U32 nStreamId;
} AXCL_SKEL_FRAME_CACHE_LIST_T;

/// @brief result struct
typedef struct axclSKEL_RESULT_T {
    AX_U64 nFrameId;
    AX_U32 nStreamId;
    AX_U32 nOriginalWidth;
    AX_U32 nOriginalHeight;
    AX_U32 nObjectSize;
    AXCL_SKEL_OBJECT_ITEM_T *pstObjectItems;
    AX_U32 nCacheListSize;
    AXCL_SKEL_FRAME_CACHE_LIST_T *pstCacheList;
    AX_VOID *pUserData;
} AXCL_SKEL_RESULT_T;

/// @brief frame struct
typedef struct axclSKEL_FRAME_T {
    AX_U64 nFrameId;
    AX_U32 nStreamId;
    AX_VIDEO_FRAME_T stFrame;
    AX_VOID *pUserData;
} AXCL_SKEL_FRAME_T;

/// @brief ppl config struct
typedef struct axclSKEL_PPL_CONFIG_T {
    AXCL_SKEL_PPL_E ePPL;
    AX_CHAR *pstrPPLConfigKey;
} AXCL_SKEL_PPL_CONFIG_T;

/// @brief capability struct
typedef struct axclSKEL_CAPABILITY_T {
    AX_U32 nPPLConfigSize;
    AXCL_SKEL_PPL_CONFIG_T *pstPPLConfig;
    AX_U32 nMetaInfoSize;
    AXCL_SKEL_META_INFO_T *pstMetaInfo;
} AXCL_SKEL_CAPABILITY_T;

/// @brief version info struct
typedef struct axclSKEL_VERSION_INFO_T {
    AX_CHAR *pstrVersion;
    AX_U32 nMetaInfoSize;
    AXCL_SKEL_META_INFO_T *pstMetaInfo;
} AXCL_SKEL_VERSION_INFO_T;

/// @brief handle definition
typedef AX_VOID *AXCL_SKEL_HANDLE;

/// @brief callback definition
typedef AX_VOID (*AXCL_SKEL_RESULT_CALLBACK_FUNC)(AXCL_SKEL_HANDLE pHandle, AXCL_SKEL_RESULT_T *pstResult, AX_VOID *pUserData);

/* begin of config param */
/// @brief Common Threshold Config
typedef struct axclSKEL_COMMON_THRESHOLD_CONFIG_T {
    AX_F32 fValue;
} AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T;
// cmd: "body_max_target_count", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "vehicle_max_target_count", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "cycle_max_target_count", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "body_confidence", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "face_confidence", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "vehicle_confidence", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "cycle_confidence", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "plate_confidence", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "crop_encoder_qpLevel", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "push_bind_enable", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "track_disable", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *
// cmd: "push_disable", value_type: AXCL_SKEL_COMMON_THRESHOLD_CONFIG_T *

/// @brief object size filter config
typedef struct axclSKEL_OBJECT_SIZE_FILTER_CONFIG_T {
    AX_U32 nWidth;
    AX_U32 nHeight;
} AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T;
// cmd: "body_min_size", value_type: AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T *
// cmd: "face_min_size", value_type: AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T *
// cmd: "vehicle_min_size", value_type: AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T *
// cmd: "cycle_min_size", value_type: AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T *
// cmd: "plate_min_size", value_type: AXCL_SKEL_OBJECT_SIZE_FILTER_CONFIG_T *

/// @brief config target item
typedef struct axclSKEL_TARGET_ITEMG_T {
    const AX_CHAR *pstrObjectCategory;
} AXCL_SKEL_TARGET_ITEM_T;

/// @brief config object target
typedef struct axclSKEL_TARGET_CONFIG_T {
    AX_U32 nSize;
    AXCL_SKEL_TARGET_ITEM_T *pstItems;
} AXCL_SKEL_TARGET_CONFIG_T;
// cmd:"target_config", value_type: AXCL_SKEL_TARGET_CONFIG_T *

typedef enum axclSKEL_ANALYZER_ATTR_E {
    AXCL_SKEL_ANALYZER_ATTR_NONE = 0,
    AXCL_SKEL_ANALYZER_ATTR_FACE_FEATURE,
    AXCL_SKEL_ANALYZER_ATTR_FACE_ATTRIBUTE,
    AXCL_SKEL_ANALYZER_ATTR_PLATE_ATTRIBUTE,
    AXCL_SKEL_ANALYZER_ATTR_MAX,
} AXCL_SKEL_ANALYZER_ATTR_E;

/// @brief config target attribute analyzer
typedef struct axclSKEL_ANALYZER_CONFIG_T {
    AX_U32 nSize;
    AXCL_SKEL_ANALYZER_ATTR_E *peItems;
} AXCL_SKEL_ANALYZER_CONFIG_T;
// cmd:"analyzer_attr_config", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *

/// @brief roi config
typedef struct axclSKEL_ROI_CONFIG_T {
    AX_BOOL bEnable;
    AXCL_SKEL_RECT_T stRect;
} AXCL_SKEL_ROI_CONFIG_T;
// cmd:"detect_roi", value_type: AXCL_SKEL_ROI_CONFIG_T*

/// @brief push mode
typedef enum axclSKEL_PUSH_MODE_E {
    AXCL_SKEL_PUSH_MODE_FAST = 1,
    AXCL_SKEL_PUSH_MODE_INTERVAL,
    AXCL_SKEL_PUSH_MODE_BEST,
    AXCL_SKEL_PUSH_MODE_MAX
} AXCL_SKEL_PUSH_MODE_E;

/// @brief push config
typedef struct axclSKEL_PUSH_STRATEGY_T {
    AXCL_SKEL_PUSH_MODE_E ePushMode;
    AX_U32 nIntervalTimes;      // only for AXCL_SKEL_PUSH_MODE_INTERVAL or AXCL_SKEL_PUSH_MODE_FAST
    AX_U32 nPushCounts;         // only for AXCL_SKEL_PUSH_MODE_INTERVAL or AXCL_SKEL_PUSH_MODE_FAST
    AX_BOOL bPushSameFrame;       // AX_FALSE: push cross frame; AX_TRUE: push same frame
} AXCL_SKEL_PUSH_STRATEGY_T;
// cmd: "push_strategy", value_type: AXCL_SKEL_ROI_CONFIG_T *

/// @brief Crop encoder threshold config
typedef struct axclSKEL_CROP_ENCODER_THRESHOLD_CONFIG_T {
    AX_F32 fScaleLeft;
    AX_F32 fScaleRight;
    AX_F32 fScaleTop;
    AX_F32 fScaleBottom;
} AXCL_SKEL_CROP_ENCODER_THRESHOLD_CONFIG_T;
// cmd:"crop_encoder",  value_type: AXCL_SKEL_CROP_ENCODER_THRESHOLD_CONFIG_T *

/// @brief Reszie panorama config
typedef struct axclSKEL_RESIZE_CONFIG_T {
    AX_F32 fW;
    AX_F32 fH;
} AXCL_SKEL_RESIZE_CONFIG_T;
// cmd:"resize_panorama_encoder_config",  value_type: AXCL_SKEL_RESIZE_CONFIG *

/// @brief push panorama config
typedef struct axclSKEL_PUSH_PANORAMA_CONFIG_T {
    AX_BOOL bEnable;
    AX_U32 nQuality;
} AXCL_SKEL_PUSH_PANORAMA_CONFIG_T;
// cmd:"push_panorama",  value_type: AXCL_SKEL_PUSH_PANORAMA_CONFIG_T *

/// @brief face attr filter config
typedef struct axclSKEL_FACE_ATTR_FILTER_CONFIG_T {
    AX_U32 nWidth;
    AX_U32 nHeight;
    AXCL_SKEL_POSE_BLUR_T stPoseblur;
} AXCL_SKEL_FACE_ATTR_FILTER_CONFIG_T;

/// @brief common attr filter config
typedef struct axclSKEL_COMMON_ATTR_FILTER_CONFIG_T {
    AX_F32 fQuality; // 0 - 1
} AXCL_SKEL_COMMON_ATTR_FILTER_CONFIG_T;

/// @brief attr filter config
typedef struct axclSKEL_ATTR_FILTER_CONFIG_T {
    union {
        AXCL_SKEL_FACE_ATTR_FILTER_CONFIG_T stFaceAttrFilterConfig;      // face
        AXCL_SKEL_COMMON_ATTR_FILTER_CONFIG_T stCommonAttrFilterConfig;  // body,vehicle,cycle,plate
    };
} AXCL_SKEL_ATTR_FILTER_CONFIG_T;
// cmd:"push_quality_face", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *
// cmd:"push_quality_body", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *
// cmd:"push_quality_vehicle", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *
// cmd:"push_quality_cycle", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *
// cmd:"push_quality_plate", value_type: AXCL_SKEL_ATTR_FILTER_CONFIG_T *

/* end of config param */

#ifdef __cplusplus
}
#endif

#endif /* _AXCL_SKEL_TYPE_H_ */
