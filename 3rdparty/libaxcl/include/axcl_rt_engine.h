/**
 * @file axcl_rt_engine.h
 *
 * Copyright (c) 2019-2024 Axera Semiconductor Co., Ltd. All Rights Reserved.
 *
 * This source file is the property of Axera Semiconductor Co., Ltd. and
 * may not be copied or distributed in any isomorphic form without the prior
 * written consent of Axera Semiconductor Co., Ltd.
**/

#ifndef __AXCL_RT_ENGINE_H__
#define __AXCL_RT_ENGINE_H__

#include "axcl_rt_engine_type.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup AxeraCL Runtime
 * @brief Initialize the runtime engine
 *
 * @par Function
 * Before using the runtime engine, the user needs to call this
 * function
 *
 * @par Restriction
 * User needs to call axclrtEngineInit to finalize the runtime
 * engine after using it
 *
 * @param npuKind [IN]     Initialize the runtime engine with
 * the specified VNPU type
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineInit(axclrtEngineVNpuKind npuKind);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get visual NPU kind
 *
 * @par Function
 * Get the runtime engine visual NPU inited kind
 *
 * @param npuKind [OUT]      VNPU type
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetVNpuKind(axclrtEngineVNpuKind *npuKind);

/**
 * @ingroup AxeraCL Runtime
 * @brief Finalize the runtime engine
 *
 * @par Function
 * After using the runtime engine, the user needs to call this
 * function
 *
 * @par Restriction
 * User needs to call axclrtEngineInit to initialize the runtime
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineFinalize();

/**
 * @ingroup AxeraCL Runtime
 * @brief Load offline model data from files
 * and manage memory internally by the system
 *
 * @par Function
 * After the system finishes loading the model,
 * the model ID returned is used as a mark to identify the model
 * during subsequent operations
 *
 * @param modelPath [IN]     Storage path for offline model files
 * @param modelId [OUT]      Model ID generated after
 *        the system finishes loading the model
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineLoadFromFile(const char *modelPath, uint64_t *modelId);

/**
 * @ingroup AxeraCL Runtime
 * @brief Load offline model data from memory and manage the memory of
 * model running internally by the system
 *
 * @par Function
 * After the system finishes loading the model,
 * the model ID returned is used as a mark to identify the model
 * during subsequent operations
 *
 * @par Restriction
 * The model memory is Device memory,
 * and requires user application and release.
 *
 * @param model [IN]         Model data stored in memory
 * @param modelSize [IN]     Model data size
 * @param modelId [OUT]      Model ID generated after
 *        the system finishes loading the model
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineLoadFromMem(const void *model, uint64_t modelSize, uint64_t *modelId);

/**
 * @ingroup AxeraCL Runtime
 * @brief unload model with model id
 *
 * @param  modelId [IN]      Model id to be unloaded
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineUnload(uint64_t modelId);

 /**
  * @ingroup AxeraCL Runtime
  * @brief get model build toolchain version
  *
  * @param  modelId [IN]      Model id
  *
  * @retval AXCL_SUCCESS The function is successfully executed.
  * @retval OtherValues Failure
 **/
const char* axclrtEngineGetModelCompilerVersion(uint64_t modelId);

/**
 * @ingroup AxeraCL Runtime
 * @brief Set model affinity
 *
 * @par Function
 * Set npu affinity for context
 *
 * @par Restriction
 * Zero is not allowed, and the masked bit of set
 * cannot out of affinity range.
 *
 * @param  modelId [IN]      Model id
 * @param  set [OUT]         The affinity set
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineCreateContext | axclrtEngineGetAffinity
**/
axclError axclrtEngineSetAffinity(uint64_t modelId, axclrtEngineSet set);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get model affinity
 *
 * @param  modelId [IN]      Model id
 * @param  set [OUT]         The affinity set
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineCreateContext | axclrtEngineSetAffinity
**/
axclError axclrtEngineGetAffinity(uint64_t modelId, axclrtEngineSet *set);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get memory usage
 *
 * @par Function
 * Get the system memory size and CMM memory size
 * required for model execution according to the model file
 *
 * @param  modelPath [IN]     Model path to get memory information
 * @param  sysSize [OUT]     The amount of working system memory for model executed
 * @param  cmmSize [OUT]     The amount of cmm memory for model executed
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetUsage(const char *modelPath, int64_t *sysSize, int64_t *cmmSize);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get memory usage
 *
 * @par Function
 * Get the system memory size and CMM memory size
 * required for model execution according the model data in memory
 *
 * @par Restriction
 * The model memory is Device memory,
 * and requires user application and release.
 * @param  model [IN]        Model memory which user manages
 * @param  modelSize [IN]    Model data size
 * @param  sysSize [OUT]     The amount of working system memory for model executed
 * @param  cmmSize [OUT]     The amount of cmm memory for model executed
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetUsageFromMem(const void *model, uint64_t modelSize, int64_t *sysSize, int64_t *cmmSize);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get memory usage
 *
 * @par Function
 * Get the system memory size and CMM memory size
 * required for model execution according the model id
 *
 * @param  modelId [IN]      Model id
 * @param  sysSize [OUT]     The amount of working system memory for model executed
 * @param  cmmSize [OUT]     The amount of cmm memory for model executed
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetUsageFromModelId(uint64_t modelId, int64_t *sysSize, int64_t *cmmSize);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get model type
 *
 * @par Function
 * Get the type of model according to the model file
 *
 * @param  modelPath [IN]     Model path to get model type
 * @param  modelType [OUT]   Model type
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetModelType(const char *modelPath, axclrtEngineModelKind *modelType);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get model type
 *
 * @par Function
 * Get the type of model according to the model data in memory
 *
 * @par Restriction
 * The model memory is Device memory,
 * and requires user application and release.
 *
 * @param  model [IN]        Model memory which user manages
 * @param  modelSize [IN]    Model data size
 * @param  modelType [IN]    Model type
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetModelTypeFromMem(const void *model, uint64_t modelSize, axclrtEngineModelKind *modelType);

 /**
  * @ingroup AxeraCL Runtime
  * @brief Get model type
  *
  * @par Function
  * Get the type of model according to the model id
  *
  * @param  modelId [IN]      Model id
  * @param  modelType [IN]    Model type
  *
  * @retval AXCL_SUCCESS The function is successfully executed.
  * @retval OtherValues Failure
 **/
axclError axclrtEngineGetModelTypeFromModelId(uint64_t modelId, axclrtEngineModelKind *modelType);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get io information
 *
 * @par Function
 * Get io information of the model according to the model ID
 *
 * @param  modelId [IN]      Model id
 * @param  ioInfo [IN]       axclrtEngineIOInfo pointer
 *
 * @par Restriction
 * Users should call axclrtEngineDestroyIOInfo to release the axclrtEngineIOInfo after using it.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineDestroyIOInfo | axclrtEngineGetIOInfoByIndex
**/
axclError axclrtEngineGetIOInfo(uint64_t modelId, axclrtEngineIOInfo *ioInfo);

/**
 * @ingroup AxeraCL Runtime
 * @brief destroy data of type axclrtEngineIOInfo
 *
 * @param  ioInfo [IN]       axclrtEngineIOInfo pointer
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineDestroyIOInfo(axclrtEngineIOInfo ioInfo);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get shape groups count
 *
 * @par Function
 * Get the number of the io shape groups
 *
 * @par Restriction
 * Pulsar2 toolchain can specify several shapes in model conversion
 * a time. There is only one shape in a normal model, and so it's no
 * needs to call this function for normally converted model.
 *
 * @param  ioInfo [IN]      axclrtEngineIOInfo pointer
 * @param  count [OUT]      Shape groups count
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineGetIOInfo | axclrtEngineGetIOInfoByIndex
**/
axclError axclrtEngineGetShapeGroupsCount(axclrtEngineIOInfo ioInfo, int32_t *count);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get the number of the inputs of
 *        the model according to data of axclrtEngineIOInfo
 *
 * @param  ioInfo [IN]       axclrtEngineIOInfo pointer
 *
 * @retval input size with axclrtEngineIOInfo
**/
uint32_t axclrtEngineGetNumInputs(axclrtEngineIOInfo ioInfo);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get the number of the output of
 *        the model according to data of axclrtEngineIOInfo
 *
 * @param  ioInfo [IN]       axclrtEngineIOInfo pointer
 *
 * @retval output size with axclrtEngineIOInfo
**/
uint32_t axclrtEngineGetNumOutputs(axclrtEngineIOInfo ioInfo);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get the size of the specified input according to
 *        the data of type axclrtEngineIOInfo
 *
 * @param  ioInfo [IN]       axclrtEngineIOInfo pointer
 * @param  group [IN]         input shape group index
 * @param  index [IN]        the size of the number of inputs to be obtained,
 *         the index value starts from 0
 *
 * @retval Specify the size of the input
**/
uint64_t axclrtEngineGetInputSizeByIndex(axclrtEngineIOInfo ioInfo, uint32_t group, uint32_t index);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get the size of the specified output according to
 *        the data of type axclrtEngineIOInfo
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param group [IN]         output shape group index
 * @param index [IN]         the size of the number of outputs to be obtained,
 *        the index value starts from 0
 *
 * @retval Specify the size of the output
**/
uint64_t axclrtEngineGetOutputSizeByIndex(axclrtEngineIOInfo ioInfo, uint32_t group, uint32_t index);

/**
 * @ingroup AxeraCL Runtime
 * @brief get input name
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param index [IN]         input io index
 *
 * @retval input tensor name,the same life cycle with ioInfo
 *
 * @see axclrtEngineGetIOInfo | axclrtEngineGetIOInfoByIndex | axclrtEngineGetNumInputs
**/
const char *axclrtEngineGetInputNameByIndex(axclrtEngineIOInfo ioInfo, uint32_t index);

/**
 * @ingroup AxeraCL Runtime
 * @brief get output name
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param index [IN]         output io index
 *
 * @retval output tensor name,the same life cycle with ioInfo
 *
 * @see axclrtEngineGetIOInfo | axclrtEngineGetIOInfoByIndex | axclrtEngineGetNumOutputs
**/
const char *axclrtEngineGetOutputNameByIndex(axclrtEngineIOInfo ioInfo, uint32_t index);

/**
 * @ingroup AxeraCL Runtime
 * @brief get input tensor index by name
 *
 * @param ioInfo [IN]        model description
 * @param name [IN]          input tensor name
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
int32_t axclrtEngineGetInputIndexByName(axclrtEngineIOInfo ioInfo, const char *name);

/**
 * @ingroup AxeraCL Runtime
 * @brief get output tensor index by name
 *
 * @param ioInfo [IN]        model description
 * @param name [IN]          output tensor name
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
int32_t axclrtEngineGetOutputIndexByName(axclrtEngineIOInfo ioInfo, const char *name);

/**
 * @ingroup AxeraCL Runtime
 * @brief get input dims info
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param group [IN]         input shape group index
 * @param index [IN]         input tensor index
 * @param dims [OUT]         dims info
 *
 * @par Restriction
 * Users should release the axclrtEngineIODims after using it.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineGetIOInfo | axclrtEngineGetIOInfoByIndex | axclrtEngineGetNumInputs
**/
axclError axclrtEngineGetInputDims(axclrtEngineIOInfo ioInfo, uint32_t group, uint32_t index, axclrtEngineIODims *dims);

/**
 * @ingroup AxeraCL Runtime
 * @brief get output dims info
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param group [IN]         output shape group index
 * @param index [IN]         output tensor index
 * @param dims [OUT]         dims info
 *
  * @par Restriction
  * Users should release the axclrtEngineIODims after using it.
  *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineGetIOInfo | axclrtEngineGetIOInfoByIndex | axclrtEngineGetNumOutputs
**/
axclError axclrtEngineGetOutputDims(axclrtEngineIOInfo ioInfo, uint32_t group, uint32_t index, axclrtEngineIODims *dims);

/**
 * @ingroup AxeraCL Runtime
 * @brief Create data of type axclrtEngineIO
 *
 * @param ioInfo [IN]        axclrtEngineIOInfo pointer
 * @param io [OUT]           The created axclrtEngineIO pointer
 *
 * @par Restriction
 * Users should call axclrtEngineDestroyIO to release the axclrtEngineIO after using it.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineCreateIO(axclrtEngineIOInfo ioInfo, axclrtEngineIO *io);

/**
 * @ingroup AxeraCL Runtime
 * @brief destroy data of type axclrtEngineIO
 *
 * @param  io [IN]           Pointer to axclrtEngineIO to be destroyed
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineDestroyIO(axclrtEngineIO io);

/**
 * @ingroup AxeraCL Runtime
 * @brief Set input data buffer by io index
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be set
 * @param index [IN]         Input tensor index
 * @param dataBuffer [IN]    data buffer address to be added
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineSetInputBufferByIndex(axclrtEngineIO io, uint32_t index, const void *dataBuffer, uint64_t size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Set output data buffer by io index
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be set
 * @param index [IN]         Output tensor index
 * @param dataBuffer [IN]    data buffer address to be added
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineSetOutputBufferByIndex(axclrtEngineIO io, uint32_t index, const void *dataBuffer, uint64_t size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Set input data buffer by io name
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be set
 * @param name [IN]          Input tensor name
 * @param dataBuffer [IN]    data buffer address to be added
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineSetInputBufferByName(axclrtEngineIO io, const char *name, const void *dataBuffer, uint64_t size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Set output data buffer by io name
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be set
 * @param name [IN]          Output tensor name
 * @param dataBuffer [IN]    data buffer address to be added
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineSetOutputBufferByName(axclrtEngineIO io, const char *name, const void *dataBuffer, uint64_t size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get input data buffer by io index
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be got
 * @param index [IN]         Input tensor index
 * @param dataBuffer [OUT]   data buffer address
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetInputBufferByIndex(axclrtEngineIO io, uint32_t index, void **dataBuffer, uint64_t *size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get output data buffer by io index
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be got
 * @param index [IN]         Output tensor index
 * @param dataBuffer [OUT]   data buffer address
 * @param size [IN]          data buffer size
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetOutputBufferByIndex(axclrtEngineIO io, uint32_t index, void **dataBuffer, uint64_t *size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get input data buffer by io name
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be got
 * @param name [IN]          Input tensor name
 * @param dataBuffer [OUT]   data buffer address
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetInputBufferByName(axclrtEngineIO io, const char *name, void **dataBuffer, uint64_t *size);

/**
 * @ingroup AxeraCL Runtime
 * @brief Get output data buffer by io name
 *
 * @param io [IN]            axclrtEngineIO address of data buffer to be got
 * @param name [IN]          Output tensor name
 * @param dataBuffer [OUT]   data buffer address
 *
 * @par Restriction
 * The data buffer is Device memory,
 * and requires user application and release.
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineGetOutputBufferByName(axclrtEngineIO io, const char *name, void **dataBuffer, uint64_t *size);

/**
 * @ingroup AxeraCL Runtime
 * @brief In dynamic batch scenarios,
 * it is used to set the number of images processed
 * at one time during model inference
 *
 * @param  io [IN]           Model inference IOs
 * @param  batchSize [IN]    Number of images processed at a time during model
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineCreateContext |
**/
axclError axclrtEngineSetDynamicBatchSize(axclrtEngineIO io, uint32_t batchSize);

/**
 * @ingroup AxeraCL Runtime
 * @brief Create a model context
 *
 * @par Function
 * Create a model running environment context for model id
 *
 * @par Restriction
 * One model id could create several running context, and
 * each of them running only with its own settings and
 * memory spaces.
 *
 * @param  modelId [IN]      Model id
 * @param  contextId [OUT]   The created context id
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclrtEngineLoadFromFile | axclrtEngineLoadFromMem
**/
axclError axclrtEngineCreateContext(uint64_t modelId, uint64_t *contextId);

/**
 * @ingroup AxeraCL Runtime
 * @brief Execute model synchronous inference until the inference result is returned
 *
 * @param  modelId [IN]      Model id
 * @param  contextId [IN]    Model inference context
 * @param  group [IN]        Model shape group index
 * @param  io [IN]           Model inference IOs
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
**/
axclError axclrtEngineExecute(uint64_t modelId, uint64_t contextId, uint32_t group, axclrtEngineIO io);

/**
 * @ingroup AxeraCL Runtime
 * @brief Execute model asynchronous inference until the inference result is returned
 *
 * @param  modelId [IN]      Model id
 * @param  contextId [IN]    Model inference context
 * @param  group [IN]        Model shape group index
 * @param  io [IN]           Model inference IOs
 * @param  stream [IN]       stream
 *
 * @retval AXCL_SUCCESS The function is successfully executed.
 * @retval OtherValues Failure
 *
 * @see axclLoadFromFile | axclLoadFromMem | axclLoadFromFileWithMem |
 * axclLoadFromMemWithMem
**/
axclError axclrtEngineExecuteAsync(uint64_t modelId, uint64_t contextId, uint32_t group, axclrtEngineIO io, axclrtStream stream);

#ifdef __cplusplus
}
#endif

#endif /* __AXCL_RT_ENGINE_H__ */
