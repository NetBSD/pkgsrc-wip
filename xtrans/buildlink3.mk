# $NetBSD: buildlink3.mk,v 1.1 2004/01/31 18:41:01 minskim Exp $
#
# This Makefile fragment is included by packages that use xtrans.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XTRANS_BUILDLINK3_MK:=	${XTRANS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xtrans
.endif

.if !empty(XTRANS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xtrans
BUILDLINK_DEPENDS.xtrans?=		xtrans>=0.1
BUILDLINK_PKGSRCDIR.xtrans?=		../../wip/xtrans

.endif # XTRANS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
