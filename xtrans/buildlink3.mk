# $NetBSD: buildlink3.mk,v 1.3 2004/06/06 16:58:33 minskim Exp $
#
# This Makefile fragment is included by packages that use xtrans.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XTRANS_BUILDLINK3_MK:=	${XTRANS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xtrans
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxtrans}
BUILDLINK_PACKAGES+=	xtrans

.if !empty(XTRANS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xtrans?=		xtrans>=0.1
BUILDLINK_PKGSRCDIR.xtrans?=		../../wip/xtrans
BUILDLINK_DEPMETHOD.xtrans?=		build
.endif # XTRANS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
