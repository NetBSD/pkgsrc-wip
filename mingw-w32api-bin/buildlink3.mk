# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	mingw-w32api-bin

.if !defined(MINGW_W32API_BIN_BUILDLINK3_MK)
MINGW_W32API_BIN_BUILDLINK3_MK:=

.include "../../wip/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-w32api-bin+=	mingw-w32api-bin>=3.1
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=	../../wip/mingw-w32api-bin
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/include,include/,g"
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif # MINGW_W32API_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w32api-bin
