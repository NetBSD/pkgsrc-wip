# $NetBSD: buildlink3.mk,v 1.3 2004/06/20 07:12:07 xtraeme Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_RUNTIME_BIN_BUILDLINK3_MK:=	${MINGW_RUNTIME_BIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-runtime-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-runtime-bin}
BUILDLINK_PACKAGES+=	mingw-runtime-bin

.include "../../wip/mingw/Makefile.common"

.if !empty(MINGW_RUNTIME_BIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mingw-runtime-bin+=	mingw-runtime-bin>=3.2
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=	../../wip/mingw-runtime-bin
BUILDLINK_TRANSFORM.mingw-runtime-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_RUNTIME_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
