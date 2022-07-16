#pragma once

#define GOD_BUILD_UNKNOW    "unknow"
#define GOD_BUILD_DEBUG     "debug"
#define GOD_BUILD_RELEASE   "release"

#if defined(SDEBUG)
#define BUILD_TYPE GOD_BUILD_DEBUG
#define GOD_DEBUG
#elif defined(SRELEASE)
#define BUILD_TYPE GOD_BUILD_RELEASE
#define GOD_RELEASE
#else
#define BUILD_TYPE GOD_BUILD_UNKNOW
#define GOD_UNKNOW
#endif