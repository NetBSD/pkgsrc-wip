# $NetBSD: buildlink3.mk,v 1.7 2008/07/26 13:51:53 obache Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_W32API_BIN_BUILDLINK3_MK:=	${MINGW_W32API_BIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mingw-w32api-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-w32api-bin}
BUILDLINK_PACKAGES+=	mingw-w32api-bin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mingw-w32api-bin

.include "../../wip/mingw/Makefile.common"

.if ${MINGW_W32API_BIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mingw-w32api-bin+=	mingw-w32api-bin>=3.1
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=	../../wip/mingw-w32api-bin
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/include,include/,g"
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_W32API_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
