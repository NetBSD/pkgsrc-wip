# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	mingw-binutils

.if !defined(MINGW_BINUTILS_BUILDLINK3_MK)
MINGW_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-binutils+=	mingw-binutils>=2.18
BUILDLINK_PKGSRCDIR.mingw-binutils?=	../../wip/mingw-binutils
.endif # MINGW_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-binutils
