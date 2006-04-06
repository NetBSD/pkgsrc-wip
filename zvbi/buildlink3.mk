# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:41 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ZVBI_BUILDLINK3_MK:=	${ZVBI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	zvbi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nzvbi}
BUILDLINK_PACKAGES+=	zvbi

.if !empty(ZVBI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.zvbi+=	zvbi>=0.2.16
BUILDLINK_PKGSRCDIR.zvbi?=	../../wip/zvbi
.endif	# ZVBI_BUILDLINK3_MK

.include "../../textproc/libunicode/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
