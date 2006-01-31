# $NetBSD: buildlink3.mk,v 1.2 2006/01/31 03:30:32 rillig Exp $

BUILDLINK_DEPMETHOD.damageproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DAMAGEPROTO_BUILDLINK3_MK:=	${DAMAGEPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	damageproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndamageproto}
BUILDLINK_PACKAGES+=	damageproto

.if !empty(DAMAGEPROTO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.damageproto+=	damageproto>=1.0.1
BUILDLINK_PKGSRCDIR.damageproto?=	../../wip/damageproto
.endif	# DAMAGEPROTO_BUILDLINK3_MK

.include "../../wip/xproto/buildlink3.mk"
.include "../../wip/fixesproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
