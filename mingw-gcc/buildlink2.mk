# $NetBSD: buildlink2.mk,v 1.1 2003/12/20 12:35:16 mpasternak Exp $
#
# This Makefile fragment is included by packages that use mingw-gcc.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(MINGW_GCC_BUILDLINK2_MK)
MINGW_GCC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mingw-gcc
BUILDLINK_DEPENDS.mingw-gcc?=		mingw-gcc>=3.3.1
BUILDLINK_PKGSRCDIR.mingw-gcc?=		../../wip/mingw-gcc

.include "../../wip/mingw-binutils/buildlink2.mk"

BUILDLINK_TARGETS+=	mingw-gcc-buildlink

mingw-gcc-buildlink: _BUILDLINK_USE

.endif	# MINGW_GCC_BUILDLINK2_MK
