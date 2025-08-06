/**
 * This file defines an 'extern "C"' wrapper.
 */
#ifndef __LLVM_C_EXTERN_EXTERN_C_H__
#define __LLVM_C_EXTERN_EXTERN_C_H__

#ifdef __clang__
#define LLVM_C_STRICT_PROTOTYPES_BEGIN \
    _Pragma("clang diagnostic push")   \
        _Pragma("clang diagnostic error \"-Wstrict-prototypes\"")
#define LLVM_C_STRICT_PROTOTYPES_END _Pragma("clang diagnostic pop")
#else
#define LLVM_C_STRICT_PROTOTYPES_BEGIN
#define LLVM_C_STRICT_PROTOTYPES_END
#endif

#ifdef __cplusplus
#define LLVM_C_EXTERN_BEGIN        \
extern "C" {                       \
    LLVM_C_STRICT_PROTOTYPES_BEGIN
    #define LLVM_C_EXTERN_C_END    \
}                                  \
#else
#define LLVM_C_EXTERN_C_BEGIN LLVM_C_STRICT_PROTOTYPES_BEGIN
#define LLVM_C_EXTERN_C_END LLVM_C_STRICT_PROTOTYPES_END
#endif

#endif /* __LLVM_C_EXTERN_EXTERN_C_H__ */
