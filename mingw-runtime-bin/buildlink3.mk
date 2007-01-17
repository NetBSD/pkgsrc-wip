# $NetBSD: buildlink3.mk,v 1.6 2007/01/17 03:11:30 rillig Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_RUNTIME_BIN_BUILDLINK3_MK:=	${MINGW_RUNTIME_BIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-runtime-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-runtime-bin}
BUILDLINK_PACKAGES+=	mingw-runtime-bin

.include "../../wip/mingw/Makefile.common"

.if !empty(MINGW_RUNTIME_BIN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mingw-runtime-bin+=	mingw-runtime-bin>=3.5
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=	../../wip/mingw-runtime-bin
BUILDLINK_FNAME_TRANSFORM.mingw-runtime-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_RUNTIME_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
