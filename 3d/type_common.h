//
// Created by coder on 2026/6/8.
//

#pragma once

#ifndef ANAN3D_TYPE_DOUBLE_
#define ANAN3D_TYPE_DOUBLE_
#define DOUBLE double
#endif

#ifndef ANAN3D_MY_DLL_H
#define ANAN3D_MY_DLL_H

#ifdef AN3DGRAPHICSLIB_EXPORTS
#define AN3DGRAPHICSLIB_API __declspec(dllexport)
#else
#define AN3DGRAPHICSLIB_API __declspec(dllimport)
#endif

#endif
