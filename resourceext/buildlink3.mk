# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 18:43:22 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use resourceext.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
RESOURCEEXT_BUILDLINK3_MK:=	${RESOURCEEXT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	resourceext
.endif

.if !empty(RESOURCEEXT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			resourceext
BUILDLINK_DEPENDS.resourceext+=		resourceext>=1.0
BUILDLINK_PKGSRCDIR.resourceext?=		../../wip/resourceext

.endif # RESOURCEEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
