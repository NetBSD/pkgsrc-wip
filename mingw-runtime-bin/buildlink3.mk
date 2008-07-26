# $NetBSD: buildlink3.mk,v 1.7 2008/07/26 13:46:39 obache Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_RUNTIME_BIN_BUILDLINK3_MK:=	${MINGW_RUNTIME_BIN_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mingw-runtime-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-runtime-bin}
BUILDLINK_PACKAGES+=	mingw-runtime-bin
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mingw-runtime-bin

.include "../../wip/mingw/Makefile.common"

.if ${MINGW_RUNTIME_BIN_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mingw-runtime-bin+=	mingw-runtime-bin>=3.5
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=	../../wip/mingw-runtime-bin
BUILDLINK_FNAME_TRANSFORM.mingw-runtime-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif	# MINGW_RUNTIME_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
