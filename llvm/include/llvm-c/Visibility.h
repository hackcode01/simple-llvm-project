/**
 * This header defines visibility macros used for the LLVM C interface. These
 * macros are used to annotate C functions that should be exported as part of
 * a shared library or DLL.
 */
#ifndef __LLVM_C_VISIBILITY_H__
#define __LLVM_C_VISIBILITY_H__

#include "../llvm/Config/llvm-config.h"

/**
 * LLVM_C_ABI is the export/visibility macro used to mark symbols declared in
 * llvm-c as exported when built as a shared library.
 */

#if !defined(LLVM_ABI_GENERATING_ANNOTATIONS)
/**
 * Eliminate need for two preprocessor definitions to gate LLVM_ABI macro definitions.
 */
#if defined(LLVM_ENABLE_LLVM_C_EXPORT_ANNOTATIONS) && \
    !defined(LLVM_BUILD_STATIC)
#if defined(_WIN32) && !defined(__MINGW32__)
#if defined(LLVM_EXPORTS)
#define LLVM_C_ABI __declspec(dllexport)
#else
#define LLVM_C_ABI __declspec(dllimport)
#endif
#elif defined(__has_attribute) && __has_attribute(visibility)
#define LLVM_C_ABI __attribute__((visibility("default")))
#endif
#endif
#if !defined(LLVM_C_ABI)
#define LLVM_C_ABI
#endif
#endif

#endif
