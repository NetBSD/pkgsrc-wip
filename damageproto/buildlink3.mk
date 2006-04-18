# $NetBSD: buildlink3.mk,v 1.4 2006/04/18 18:27:50 jeremy-c-reed Exp $

BUILDLINK_DEPMETHOD.damageproto?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DAMAGEPROTO_BUILDLINK3_MK:=	${DAMAGEPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	damageproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndamageproto}
BUILDLINK_PACKAGES+=	damageproto

.if !empty(DAMAGEPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.damageproto+=	damageproto>=1.0.1
BUILDLINK_PKGSRCDIR.damageproto?=	../../wip/damageproto
.endif	# DAMAGEPROTO_BUILDLINK3_MK

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
