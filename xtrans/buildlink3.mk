# $NetBSD: buildlink3.mk,v 1.2 2004/03/18 15:40:57 jeremy-c-reed Exp $
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
.endif # XTRANS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
