# $NetBSD: buildlink3.mk,v 1.7 2009/05/06 10:02:47 cheusov Exp $

BUILDLINK_TREE+=	mingw-gcc

.if !defined(MINGW_GCC_BUILDLINK3_MK)
MINGW_GCC_BUILDLINK3_MK:=

.include "../../wip/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-gcc+=	mingw-gcc>=3.4.2
BUILDLINK_PKGSRCDIR.mingw-gcc?=	../../wip/mingw-gcc
BUILDLINK_FNAME_TRANSFORM.mingw-gcc+=	-e "s,${MINGW_TARGET}/lib,lib/,g"

.include "../../wip/mingw-binutils/buildlink3.mk"
.endif # MINGW_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-gcc
