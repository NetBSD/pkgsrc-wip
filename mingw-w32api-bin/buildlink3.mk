# $NetBSD: buildlink3.mk,v 1.4 2006/04/06 07:18:02 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_W32API_BIN_BUILDLINK3_MK:=	${MINGW_W32API_BIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-w32api-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-w32api-bin}
BUILDLINK_PACKAGES+=	mingw-w32api-bin

.include "../../wip/mingw/Makefile.common"

.if !empty(MINGW_W32API_BIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mingw-w32api-bin+=	mingw-w32api-bin>=3.1
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=	../../wip/mingw-w32api-bin
BUILDLINK_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/include,include/,g"
BUILDLINK_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_W32API_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
