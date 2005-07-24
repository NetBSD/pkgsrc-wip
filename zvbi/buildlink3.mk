# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/24 23:43:17 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZVBI_BUILDLINK3_MK:=	${ZVBI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zvbi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nzvbi}
BUILDLINK_PACKAGES+=	zvbi

.if !empty(ZVBI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.zvbi+=	zvbi>=0.2.16
BUILDLINK_PKGSRCDIR.zvbi?=	../../wip/zvbi
.endif	# ZVBI_BUILDLINK3_MK

.include "../../textproc/libunicode/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
