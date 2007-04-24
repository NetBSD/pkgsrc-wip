/* $NetBSD: math.h,v 1.1 2007/04/24 13:36:36 tnn2 Exp $ */
#ifndef __hpux
#error This header file doesn't apply to this platform.
#endif

#ifndef _PKGSRC_MATH_H_
#define _PKGSRC_MATH_H_
#ifdef __hpux
#include "/usr/include/math.h"
#define floorf(x)	((float)floor (x))
#define ceilf(x)	((float)ceil (x))
#define sinf(x)		((float)sin (x))
#define cosf(x)		((float)cos (x))
#define tanf(x)		((float)tan (x))
#define asinf(x)	((float)asin (x))
#define acosf(x)	((float)acos (x))
#define atanf(x)	((float)atan (x))
#define atan2f(x,y)	((float)atan2 (x, y))
#define sqrtf(x)	((float)sqrt (y))
#endif /* __hpux */
#endif /* _PKGSRC_MATH_H_ */
