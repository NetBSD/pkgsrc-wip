# $NetBSD: buildlink2.mk,v 1.1 2003/11/29 19:39:13 mpasternak Exp $
#
# This Makefile fragment is included by packages that use mingw-c.

.if !defined(MINGW_C_BUILDLINK2_MK)
MINGW_C_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mingw-c
BUILDLINK_DEPENDS.mingw-c?=		mingw-c>=3.1.1
BUILDLINK_PKGSRCDIR.mingw-c?=		../../wip/mingw-c

EVAL_PREFIX+=	BUILDLINK_PREFIX.mingw-c=mingw-c
BUILDLINK_PREFIX.mingw-c_DEFAULT=	${CROSSBASE}
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/cc1
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/crtbegin.o
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/crtend.o
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/README
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/float.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/iso646.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/limits.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/mmintrin.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/stdarg.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/stdbool.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/stddef.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/syslimits.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/unwind.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/varargs.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/include/xmmintrin.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/fixinc.sh
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/gsyslimits.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/README
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/float.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/iso646.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/limits.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/mmintrin.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/stdarg.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/stdbool.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/stddef.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/unwind.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/varargs.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/include/xmmintrin.h
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/mkheaders
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/install-tools/mkheaders.conf
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/libgcc.*
BUILDLINK_FILES.mingw-c+=	lib/gcc-lib/i586-mingw32/3.3.1/specs
BUILDLINK_FILES.mingw-c+=	lib/libiberty.*
BUILDLINK_FILES.mingw-c+= bin/i586-mingw32-cpp bin/i586-mingw32-gcc \
			  bin/i586-mingw32-gcc-3.3.1 bin/i586-mingw32-gccbug \
			  bin/i586-mingw32-gcov

.include "../../wip/mingw-binutils/buildlink2.mk"
.include "../../wip/mingw-runtime-bin/buildlink2.mk"

BUILDLINK_TARGETS+=	mingw-c-buildlink

mingw-c-buildlink: _BUILDLINK_USE

.endif	# MINGW_C_BUILDLINK2_MK
