# $NetBSD: buildlink3.mk,v 1.1 2004/01/31 17:56:11 minskim Exp $
#
# This Makefile fragment is included by packages that use xproto.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XPROTO_BUILDLINK3_MK:=	${XPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xproto
.endif

.if !empty(XPROTO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xproto
BUILDLINK_DEPENDS.xproto?=		xproto>=6.6
BUILDLINK_PKGSRCDIR.xproto?=		../../wip/xproto


.endif # XPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
