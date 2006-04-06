# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:24 jeremy-c-reed Exp $
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
BUILDLINK_API_DEPENDS.resourceext+=		resourceext>=1.0
BUILDLINK_PKGSRCDIR.resourceext?=		../../wip/resourceext

.endif # RESOURCEEXT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
