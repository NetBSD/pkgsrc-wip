# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/11/10 02:57:29 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.resourceprotoproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RESOURCEPROTOPROTO_BUILDLINK3_MK:=	${RESOURCEPROTOPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	resourceprotoproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nresourceprotoproto}
BUILDLINK_PACKAGES+=	resourceprotoproto

.if !empty(RESOURCEPROTOPROTO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.resourceprotoproto+=	resourceprotoproto>=1.0.1
BUILDLINK_PKGSRCDIR.resourceprotoproto?=	../../wip/resourceprotoproto
.endif	# RESOURCEPROTOPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
