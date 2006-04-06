# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:12 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use QUANTA.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
QUANTA_BUILDLINK3_MK:=	${QUANTA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	QUANTA
.endif

.if !empty(QUANTA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			QUANTA
BUILDLINK_API_DEPENDS.QUANTA+=		QUANTA>=0.3
BUILDLINK_PKGSRCDIR.QUANTA?=		../../wip/QUANTA

.endif # QUANTA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
