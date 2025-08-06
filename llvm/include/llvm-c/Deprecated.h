/**
 * This header declares LLVM_ATTRIBUTE_C_DEPRECATED() macro, which can be
 * used to deprecate functions in the C interface.
 */
#ifndef __LLVM_C_DEPRECATED_H__
#define __LLVM_C_DEPRECATED_H__

#ifndef __has_feature
#define __has_feature(x) 0
#endif

/**
 * This is a variant of LLVM_ATTRIBUTE_DEPRECATED() that is compatible with C compilers.
 */
#if __has_feature(attribute_deprecated_with_message)
#define LLVM_ATTRIBUTE_C_DEPRECATED(decl, message) \
    decl __attribute__((deprecated(message)))
#elif defined(__GNUC__)
#define LLVM_ATTRIBUTE_C_DEPRECATED(decl, message) \
    decl __attribute__((deprecated))
#elif defined(_MSC_VER)
#define LLVM_ATTRIBUTE_C_DEPRECATED(decl, message) \
    __declspec(deprecated(message)) decl
#else
#define LLVM_ATTRIBUTE_C_DEPRECATED(decl, message) \
    decl
#endif

#endif /* __LLVM_C_DEPRECATED_H__ */
