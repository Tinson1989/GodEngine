#pragma once

#include"Configuration/BuildType.h"

#if defined(_WINDOWS)
#include<crtdbg.h>
#define GOD__ASSERT_IMPL(EXPR) _ASSERTE(EXPR)
#else 
#endif

#if defined(GOD_DEBUG)
#define Assert(EXPR) GOD__ASSERT_IMPL(EXPR)
#elif defined(GOD_RELEASE)
#define Assert(EXPR) ((void)0)
#else
#define Assert(EXPR) ((void)0)
#endif