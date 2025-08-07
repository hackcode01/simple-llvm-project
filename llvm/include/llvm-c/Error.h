/**
 * This file defines the C interfaces to LLVM's Error class.
 */
#ifndef __LLVM_C_ERROR_H__
#define __LLVM_C_ERROR_H__

#include "llvm-c/ExternC.h"
#include "llvm-c/Visibility.h"

LLVM_C_EXTERN_C_BEGIN

/**
 * @defgroup LLVMCError Error Handling
 * @ingroup LLVMC
 * @{
 */

#define LLVMErrorSuccess 0

/**
 * Opaque references to an error instance. Null serves as the 'success' value.
 */
typedef struct LLVMOpaqueError *LLVMErrorRef;

/**
 * Error type identifier.
 */
typedef const void *LLVMErrorTypeId;

/**
 * Returns the type id for given error instance, which must be a failure
 * value (i.e. non-null)
 */
LLVM_C_ABI LLVMErrorTypeId LLVMGetErrorTypeId(LLVMErrorRef error);

/**
 * Dispose of the given error without handling it. This operation consumes the
 * error, and the given LLVMErrorRef value is not usable once this call returns.
 * Note: This method *only* needs to be called if the error is not being passed
 * to some other consuming operation, e.g. LLVMGetErrorMessage.
 */
LLVM_C_ABI void LLVMConsumeError(LLVMErrorRef error);

/**
 * Report a fatal error if Err is a failure value.
 *
 * This function can be used to wrap calls to fallible functions ONLY when it is
 * known that the Error will always be a success value.
 */
LLVM_C_ABI void LLVMCantFail(LLVMErrorRef error);

/**
 * Returns the given string's error message. This operation consumes the error,
 * and the given LLVMErrorRef value is not usable once this call returns.
 * The caller is responsible for disposing of the string by calling
 * LLVMDisposeErrorMessage.
 */
LLVM_C_ABI char *LLVMGetErrorMessage(LLVMErrorRef error);

/**
 * Dispose of the given error message.
 */
LLVM_C_ABI void LLVMDisposeErrorMessage(char *errorMessage);

/**
 * Returns the type id for llvm StringError.
 */
LLVM_C_ABI LLVMErrorTypeId LLVMGetStringErrorTypeId(void);

/**
 * Create a StringError.
 */
LLVM_C_ABI LLVMErrorRef LLVMCreateStringError(const char *errorMessage);

/**
 * @}
 */

LLVM_C_EXTERN_C_END

#endif
