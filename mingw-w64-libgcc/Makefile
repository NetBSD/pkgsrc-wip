# $NetBSD: Makefile,v 1.1.1.1 2010/08/11 15:11:01 tnn2 Exp $

PKGNAME=	mingw-w64-lib${DISTNAME:S/4.5-/4.5./}
COMMENT=	GCC target libraries for win32/64 cross-development

DEPENDS+=	mingw-w64-crt-[0-9]*:../../wip/mingw-w64-crt

INSTALL_TARGET=	install-target

HAVE_FUNCS=	_finitef _isnanf acosf acosl asinf asinl atan2f atan2l atanf atanl ceilf ceill cosf coshf coshl cosl expf expl fabsf fabsl finite floorf floorl fmodf fmodl fpclass frexpf frexpl hypot hypotf hypotl isinf isnan ldexpf ldexpl log10f log10l logf logl modf modff modfl powf powl sinf sinhf sinhl sinl sqrtf sqrtl strtof strtold tanf tanhf tanhl tanl

# Wire down libstdc++ configure tests that don't work in cross-compile env
MAKE_ENV+=	ac_cv_lib_m_sin=yes
MAKE_ENV+=	${HAVE_FUNCS:C/.*/ac_cv_func_&=yes/}

.include "../../wip/mingw-w64-gcc/Makefile.common"
