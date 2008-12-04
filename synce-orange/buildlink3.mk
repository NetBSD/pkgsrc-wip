# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/04 23:08:21 shattered Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ORANGE_BUILDLINK3_MK:=	${ORANGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	orange
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Norange}
BUILDLINK_PACKAGES+=	orange
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}orange

.if !empty(ORANGE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.orange+=	orange>=0.3
BUILDLINK_PKGSRCDIR.orange?=		../../wip/synce-orange
.endif	# ORANGE_BUILDLINK3_MK

.include "../../archivers/unshield/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../wip/synce-dynamite/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
