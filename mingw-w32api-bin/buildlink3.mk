# $NetBSD: buildlink3.mk,v 1.2 2004/06/20 07:06:21 xtraeme Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_W32API_BIN_BUILDLINK3_MK:=	${MINGW_W32API_BIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-w32api-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-w32api-bin}
BUILDLINK_PACKAGES+=	mingw-w32api-bin

.include "../../wip/mingw/Makefile.common"

.if !empty(MINGW_W32API_BIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mingw-w32api-bin+=	mingw-w32api-bin>=2.4
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=	../../wip/mingw-w32api-bin
BUILDLINK_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/include,include/,g"
BUILDLINK_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_W32API_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
