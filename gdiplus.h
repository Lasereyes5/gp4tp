/**
 * This file is a compatible GDI+ header for Tiny C Compiler.
 * 
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the gp4pt package.
 * No warranty is given; refer to the file LICENSE within this package.
 */
#ifdef __TINYC__
#include "winapigp/wtypes.h"
#pragma comment(lib,"gdiplus")
#else
/* keep gcc compatibilty */
#include <wtypes.h>
#endif

#include "gdiplus/gdiplus.h"
