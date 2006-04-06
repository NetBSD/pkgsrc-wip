# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:24 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUILERXSPENCER_BUILDLINK3_MK:=	${GUILERXSPENCER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guilerxspencer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguilerxspencer}
BUILDLINK_PACKAGES+=	guilerxspencer

.if !empty(GUILERXSPENCER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.guilerxspencer+=	guilerxspencer>=1.2
BUILDLINK_PKGSRCDIR.guilerxspencer?=	../../wip/guilerxspencer
.endif	# GUILERXSPENCER_BUILDLINK3_MK

.include "../../lang/guile/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
