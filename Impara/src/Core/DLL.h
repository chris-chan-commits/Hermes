#pragma once

#ifdef IMPARA_BUILD_DLL
#define IMPARA_API __declspec(dllexport)
#else
#define IMPARA_API __declspec(dllimport)
#endif