# $NetBSD: buildlink3.mk,v 1.1 2004/01/31 18:12:18 minskim Exp $
#
# This Makefile fragment is included by packages that use xextensions.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XEXTENSIONS_BUILDLINK3_MK:=	${XEXTENSIONS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xextensions
.endif

.if !empty(XEXTENSIONS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xextensions
BUILDLINK_DEPENDS.xextensions?=		xextensions>=1.0
BUILDLINK_PKGSRCDIR.xextensions?=		../../wip/xextensions

.endif # XEXTENSIONS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
