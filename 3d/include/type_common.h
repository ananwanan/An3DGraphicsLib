//
// Created by coder on 2026/6/8.
//
#pragma once

// ================================
// AN3D Symbol Visibility
// ================================

// AN3D_STATIC:
// 编译静态库时定义
//
// AN3DGRAPHICSLIB_EXPORTS:
// 编译 DLL 时由 CMake 自动定义
//

#if defined(AN3D_STATIC)

    #define AN3D_API
    #define AN3D_LOCAL

#else

    // ============================
    // Windows
    // ============================
    #if defined(_WIN32) || defined(__CYGWIN__)

        #ifdef AN3DGRAPHICSLIB_EXPORTS
            #define AN3D_API __declspec(dllexport)
        #else
            #define AN3D_API __declspec(dllimport)
        #endif

        #define AN3D_LOCAL

    // ============================
    // GCC / Clang
    // ============================
    #elif defined(__GNUC__) || defined(__clang__)

        #if __GNUC__ >= 4
            #define AN3D_API   __attribute__((visibility("default")))
            #define AN3D_LOCAL __attribute__((visibility("hidden")))
        #else
            #define AN3D_API
            #define AN3D_LOCAL
        #endif

    // ============================
    // Other Compiler
    // ============================
    #else

        #define AN3D_API
        #define AN3D_LOCAL

    #endif

#endif

// ================================
// Deprecated
// ================================

#if defined(_MSC_VER)

    #define AN3D_DEPRECATED __declspec(deprecated)

#elif defined(__GNUC__) || defined(__clang__)

    #define AN3D_DEPRECATED __attribute__((deprecated))

#else

    #define AN3D_DEPRECATED

#endif