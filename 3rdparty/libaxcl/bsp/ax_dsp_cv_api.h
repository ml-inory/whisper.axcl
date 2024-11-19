/**************************************************************************************************
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
 *
 **************************************************************************************************/

#ifndef _AX_DSP_CV_API_H_
#define _AX_DSP_CV_API_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#include <ax_dsp_api.h>
#include "ax_global_type.h"

//These CMDs are follow in AX_DSP_CMD_E
#define AX_DSP_CMD_OPERATOR_CVTCOLOR (AX_DSP_CMD_OPERATOR + 2)
#define AX_DSP_CMD_OPERATOR_JOINT_LR (AX_DSP_CMD_OPERATOR + 3)
#define AX_DSP_CMD_OPERATOR_SAD (AX_DSP_CMD_OPERATOR + 4)
#define AX_DSP_CMD_OPERATOR_MAP (AX_DSP_CMD_OPERATOR + 7)
#define AX_DSP_CMD_OPERATOR_NV12COPY (AX_DSP_CMD_OPERATOR + 8)
#define AX_DSP_CMD_OPERATOR_NV12Blending (AX_DSP_CMD_OPERATOR + 9)
#define AX_DSP_CMD_OPERATOR_COPY (AX_DSP_CMD_OPERATOR + 10)
#define AX_DSP_CMD_OPERATOR_SAD_EX (AX_DSP_CMD_OPERATOR + 13)
#define AX_DSP_CMD_OPERATOR_FIK 0x100

typedef enum {
    E_Scale_U8,
    E_FilterSobel_U8,
    E_IntegralImage_U8U32,
    E_FilterSobel_U8S16,
    E_FilterGaussian_U8,
    E_RGBToYUV420_U8,
    E_YUV420ToRGB_U8,
    E_RGBToGray_U8,
    E_Transpose_U8,
    E_AffineTransform_U8,
    E_PerspectiveTransform_U8,
    E_YUV420To444_U8,
    E_ConnectedComponent_U8U16,
    E_Canny,
    E_MedianBlur_U8,
    E_Dilate_U8,
    E_Erode_U8,
    E_BoxFilter_U8,
    E_GuidedFilter_U8,
    E_BilateralFilter,
    E_PyrDown_U8,
    E_PyrDown_S16,
    E_LKTrackPoint_U8,
    E_LKTrackPoint_S16,
    E_LKPyrDown_U8,
    E_LKPyrDown_S16,
    E_CornerHarris,
    E_Census_U8,
    E_FlipHorizontal,
    E_FlipVertical,
    E_FilterFAST_U8,
    E_FilterFAST_S16,
    E_NonMaximaSuppression,
    E_Ncc,
    E_TemplateMatch,
    E_ExtractPoints_U8,
    E_ExtractPoints_S16,
    E_CornerHarris_NonMaxima,
    E_sort_S16,
    E_ExtractPoints_S32,
    E_ExtractKeyPoints_U8,
    E_CalcHist,
    E_EqualizeHist,
    E_PyrUp_U8,
    E_PyrUp_S16,
    E_SepFilter2d_R_U8,
    E_SepFilter2d_R_S16,
    E_SepFilter2d_D_U8,
    E_SepFilter2d_D_S16,
    E_Filter2d_R_U8,
    E_Filter2d_R_S16,
    E_Filter2d_D_U8,
    E_Filter2d_D_S16,
    E_LaplacianPyrDown_U8,
    E_LaplacianReconstruct_S16,
    E_LaplacianReconstruct2_S16,
    E_LBP_U8,
    E_MLBP_U8,
    E_ULBP_U8,
    E_MCT_U8U16,
    E_MCT_S16U16,
    E_BoxFilter_S16,
    E_FilterGaussian_R_U8,
    E_Convolve_RS_U8,
    E_Upsample2XNearest_I8,
    E_Laplacian3x3_U8S16,
    E_RemapNearest_I8,
    E_CornerShiTomasi,
    E_OpticalFlowBM_U8,
    E_PrepareHoughLines,
    E_GatherLocationsEq,
    E_HoughLinesTransform,
    E_HoughLinesExtract,
    E_CircleFilter_U8,
    E_CircleFilter_U16_U8
} AX_DSP_CV_FIK_ID_E;

typedef struct {
    AX_U64 u64PhyAddr;  // the physical address of the memory
    AX_U64 u64VirAddr;  // the virtual address of the memory
    AX_U32 u32Size;     // the size of memory
} AX_MEM_INFO_T;

typedef enum {
    U8_TO_U8,
    U8_TO_S16,
    U8_TO_U16,
    U8_TO_S32,
    S16_TO_U8,
    S16_TO_S16,
    S16_TO_U16,
    S16_TO_S32,
    U16_TO_U16,
    U16_TO_S32,
    S32_TO_S32,
} AX_DSP_CV_DTYPE_E;

typedef struct {
    int format;
    int src_height;
    int src_width;
    int src_stride;
    int dst_height;
    int dst_width;
    int dst_stride;
    int inter_type;
} AX_DSP_CV_RESIZE_PARAM_T;

typedef enum {
    AX_DSP_CV_ERR_NODSPID = -1000,
    AX_DSP_CV_ERR_NOTREADY,
    AX_DSP_CV_ERR_NOMEM,
    AX_DSP_CV_ERR_PROC,
    AX_DSP_CV_ERR_QUERY,
    AX_DSP_CV_ERR_MEMOP,
    AX_DSP_CV_ERR_OPER,
    AX_DSP_CV_ERR_UNSUPPORT,
} AX_DSP_CV_ERR_E;

typedef enum {
    AX_DSP_CV_FORMAT_NV12,
    AX_DSP_CV_FORMAT_Y8,
    AX_DSP_CV_FORMAT_UV8,
} AX_DSP_CV_FORMAT_E;

enum {
    AX_DSP_CV_RESIZE_INNER_TYPE_BILINEAR,
    AX_DSP_CV_RESIZE_INNER_TYPE_NEAREST,
    AX_DSP_CV_RESIZE_INNER_TYPE_BUTT,
};

typedef struct {
    int src_height;
    int src_width;
    int src_stride;
    int src_stride_uv;
    int dst_stride;
} AX_DSP_CV_CVTCOLOR_PARAM_T;

typedef enum {
    AX_DSP_CV_CVTCOLOR_NV12_YUYV,
    AX_DSP_CV_CVTCOLOR_YUV444_RGBX,
    AX_DSP_CV_CVTCOLOR_RGB_DEINTERLEAVE,
    AX_DSP_CV_CVTCOLOR_RGB_INTERLEAVE,
    AX_DSP_CV_CVTCOLOR_FORMAT_BUTT,
} AX_DSP_CV_CVTCOLOR_FORMAT_E;

/* Type of the AX_DSP_IMAGE_T */
typedef enum {
    AX_DSP_CV_IMAGE_TYPE_U8C1 = 0x0,
    AX_DSP_CV_IMAGE_TYPE_S8C1 = 0x1,

    AX_DSP_CV_IMAGE_TYPE_YUV420SP = 0x2, /* YUV420 SemiPlanar */
    AX_DSP_CV_IMAGE_TYPE_YUV422SP = 0x3, /* YUV422 SemiPlanar */
    AX_DSP_CV_IMAGE_TYPE_YUV420P = 0x4,  /* YUV420 Planar */
    AX_DSP_CV_IMAGE_TYPE_YUV422P = 0x5,  /* YUV422 planar */

    AX_DSP_CV_IMAGE_TYPE_S8C2_PACKAGE = 0x6,
    AX_DSP_CV_IMAGE_TYPE_S8C2_PLANAR = 0x7,

    AX_DSP_CV_IMAGE_TYPE_S16C1 = 0x8,
    AX_DSP_CV_IMAGE_TYPE_U16C1 = 0x9,

    AX_DSP_CV_IMAGE_TYPE_U8C3_PACKAGE = 0xa,
    AX_DSP_CV_IMAGE_TYPE_U8C3_PLANAR = 0xb,

    AX_DSP_CV_IMAGE_TYPE_S32C1 = 0xc,
    AX_DSP_CV_IMAGE_TYPE_U32C1 = 0xd,

    AX_DSP_CV_IMAGE_TYPE_S64C1 = 0xe,
    AX_DSP_CV_IMAGE_TYPE_U64C1 = 0xf,

    AX_DSP_CV_IMAGE_TYPE_BUTT

} AX_DSP_CV_IMAGE_TYPE_E;

/* Definition of the AX_DSP_IMAGE_T */
typedef struct {
    AX_U64 au64PhyAddr[3];   /* RW;The physical address of the image */
    AX_U64 au64VirAddr[3];   /* RW;The virtual address of the image */
    AX_U32 au32Stride[3];    /* RW;The stride of the image */
    AX_U32 u32Width;         /* RW;The width of the image */
    AX_U32 u32Height;        /* RW;The height of the image */
    AX_DSP_CV_IMAGE_TYPE_E enType; /* RW;The type of the image */
} AX_DSP_CV_IMAGE_T;

typedef struct {
    AX_U64 phySrcL;
    AX_U64 phySrcR;
    AX_U64 phyDst;
    int width_l;
    int width_r;
    int height;
    int src_stride_l;
    int src_stride_r;
    int dst_stride;
} AX_DSP_CV_JOINTLR_PARAM_T;

typedef struct {
    AX_U64 phySrcL;
    AX_U64 phySrcR;
    AX_U64 phyDst;
    int width;
    int height;
    int src_stride_l;
    int src_stride_r;
    int dst_stride;
    int kernel_size;
    int range;
} AX_DSP_CV_SAD_PARAM_T;

/* Sad mode */
typedef enum {
    AX_DSP_CV_SAD_MODE_MB_16X16 = 0x0,   /* 4x4 */
    AX_DSP_CV_SAD_MODE_MB_8X8 = 0x1,   /* 4x4 */
    AX_DSP_CV_SAD_MODE_MB_4X4 = 0x2,   /* 4x4 */
    AX_DSP_CV_SAD_MODE_BUTT
} AX_DSP_CV_SAD_MODE_E;

/* Sad output ctrl */
typedef enum {
    AX_DSP_CV_SAD_OUT_CTRL_8BIT_BOTH = 0x0,  /* Output 8 bit sad and thresh */
    AX_DSP_CV_SAD_OUT_CTRL_8BIT_SAD = 0x1,   /* Output 8 bit sad */
    AX_DSP_CV_SAD_OUT_CTRL_THRESH = 0x2,     /* Output thresh */

    AX_DSP_CV_SAD_OUT_CTRL_BUTT
} AX_DSP_CV_SAD_OUT_CTRL_E;

/* Sad control parameters */
typedef struct axIVE_SAD_CTRL_T {
    AX_DSP_CV_SAD_MODE_E enMode;
    AX_DSP_CV_SAD_OUT_CTRL_E enOutCtrl;
    AX_U16 u16Thr;  /* user-defined threshold: srcVal<=u16Thr, dstVal=minVal; srvVal>u16Thr, DstVal=maxVal*/
    AX_U8 u8MinVal;  /* Minimum value when tri-level thresholding */
    AX_U8 u8MaxVal;  /* Maxmum value when tri-level thresholding */
} AX_DSP_CV_SAD_CTRL_T;

typedef struct {
    AX_DSP_CV_IMAGE_T stSrc1;
    AX_DSP_CV_IMAGE_T stSrc2;
    AX_DSP_CV_IMAGE_T stSad;
    AX_DSP_CV_IMAGE_T stThr;
    AX_DSP_CV_SAD_CTRL_T stSadCtrl;
} AX_DSP_CV_SAD_EX_PARAM_T;

typedef struct {
    AX_U64 phySrc;
    AX_U64 phyMap;
    AX_U64 phyDst;
    int width;
    int height;
    int src_stride;
    int dst_stride;
    int para;
} AX_DSP_CV_MAP_PARAM_T;

typedef struct {
    AX_U64 phySrc_y;
    AX_U64 phySrc_uv;
    AX_U64 phyDst_y;
    AX_U64 phyDst_uv;
    int src_height;
    int src_stride;
    int dst_width;
    int dst_height;
    int dst_stride;
    int src_x; //x should be even
    int src_y;
    int win_w;
    int win_h;
    int dst_x; //x should be even
    int dst_y;
    int para;
} AX_DSP_CV_NV12COPY_PARAM_T;

typedef struct {
    AX_U64 phySrc_NV12;
    AX_U64 phySrc_RGBA;
    AX_U64 phyDst;
    int width;
    int height;
    int src_stride_NV12;
    int src_stride_RGBA;
    int dst_stride;
    int src_x; //x should be even
    int src_y; //y should be even
    int win_w; //should be even
    int win_h; //should be even
    int para; //0:rgba
} AX_DSP_CV_NV12Blending_PARAM_T;

typedef struct {
    AX_U64 phySrc;
    AX_U64 phyDst;
    int src_stride;
    int dst_stride;
    int win_w;
    int win_h;
    int para;
} AX_DSP_CV_COPY_PARAM_T;

int AX_DSP_CV_Init(int dsp_id);
int AX_DSP_CV_ResizeAll(int dsp_id, AX_MEM_INFO_T in_buf[3], AX_MEM_INFO_T out_buf[3], AX_DSP_CV_RESIZE_PARAM_T *param);
int AX_DSP_CV_Resize(int dsp_id, AX_MEM_INFO_T *in_buf, AX_MEM_INFO_T *out_buf, AX_DSP_CV_RESIZE_PARAM_T *param);
int AX_DSP_CV_ResizeUV(int dsp_id, AX_MEM_INFO_T *in_buf, AX_MEM_INFO_T *out_buf, AX_DSP_CV_RESIZE_PARAM_T *param);
int AX_DSP_CV_CvtColor(int dsp_id, int format, AX_MEM_INFO_T in_buf[3], AX_MEM_INFO_T out_buf[3],
                       AX_DSP_CV_CVTCOLOR_PARAM_T *param);
int AX_DSP_CV_JointLR(int dsp_id, AX_DSP_CV_JOINTLR_PARAM_T *param);
int AX_DSP_CV_SAD(int dsp_id, AX_DSP_CV_SAD_PARAM_T *param);
int AX_DSP_CV_SAD_EX(int dsp_id, AX_DSP_CV_SAD_EX_PARAM_T *param);
int AX_DSP_CV_MAP(int dsp_id, AX_DSP_CV_MAP_PARAM_T *param);
int AX_DSP_CV_NV12COPY(int dsp_id, AX_DSP_CV_NV12COPY_PARAM_T *param);
int AX_DSP_CV_NV12Blending(int dsp_id, AX_DSP_CV_NV12Blending_PARAM_T *param);
int AX_DSP_CV_COPY(int dsp_id, AX_DSP_CV_COPY_PARAM_T *param);
int AX_DSP_CV_FIK(int dsp_id, int fik_id, void *param, int param_size);
int AX_DSP_CV_Exit(int dsp_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
#endif/*_AX_SVP_DSP_CV_H_*/

