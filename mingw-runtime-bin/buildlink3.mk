# $NetBSD: buildlink3.mk,v 1.1 2004/05/10 22:04:41 blef Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
MINGW_RUNTIME_BIN_BUILDLINK3_MK:=	${MINGW_RUNTIME_BIN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mingw-runtime-bin
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmingw-runtime-bin}
BUILDLINK_PACKAGES+=	mingw-runtime-bin

.if !empty(MINGW_RUNTIME_BIN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mingw-runtime-bin+=	mingw-runtime-bin>=3.2
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=	../../wip/mingw-runtime-bin
.endif	# MINGW_RUNTIME_BIN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
