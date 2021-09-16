#ifndef NCORE_GLOBAL_H
#define NCORE_GLOBAL_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define NC_DECL_EXPORT __declspec(dllexport)
#  define NC_DECL_IMPORT __declspec(dllimport)
#else
#  define NC_DECL_EXPORT     __attribute__((visibility("default")))
#  define NC_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(NCORE_LIBRARY)
#  define NCORE_EXPORT NC_DECL_EXPORT
#else
#  define NCORE_EXPORT NC_DECL_IMPORT
#endif

#endif // NCORE_GLOBAL_H
