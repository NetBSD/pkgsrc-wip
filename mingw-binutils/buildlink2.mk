# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/29 18:16:30 mpasternak Exp $
#
# This Makefile fragment is included by packages that use mingw-binutils.
#

.if !defined(MINGW_BINUTILS_BUILDLINK2_MK)
MINGW_BINUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mingw-binutils
BUILDLINK_DEPENDS.mingw-binutils?=		mingw-binutils>=2.14.90
BUILDLINK_PKGSRCDIR.mingw-binutils?=		../../wip/mingw-binutils

EVAL_PREFIX+=	BUILDLINK_PREFIX.mingw-binutils=mingw-binutils
BUILDLINK_PREFIX.mingw-binutils_DEFAULT=	${CROSSBASE}
BUILDLINK_FILES.mingw-binutils+=	\
	bin/i586-mingw32-addr2line bin/i586-mingw32-ar \
	bin/i586-mingw32-as bin/i586-mingw32-c++filt \
	bin/i586-mingw32-dlltool bin/i586-mingw32-dllwrap \
	bin/i586-mingw32-ld bin/i586-mingw32-nm \
	bin/i586-mingw32-objcopy bin/i586-mingw32-objdump \
	bin/i586-mingw32-ranlib bin/i586-mingw32-readelf \
	bin/i586-mingw32-size bin/i586-mingw32-strings \
	bin/i586-mingw32-strip bin/i586-mingw32-windres lib/libiberty.* 

BUILDLINK_TARGETS+=	mingw-binutils-buildlink

mingw-binutils-buildlink: _BUILDLINK_USE

.endif	# MINGW_BINUTILS_BUILDLINK2_MK
