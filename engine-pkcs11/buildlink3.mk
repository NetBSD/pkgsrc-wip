# $NetBSD: buildlink3.mk,v 1.1 2006/03/25 18:34:55 udontknow Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ENGINE_PKCS11_BUILDLINK3_MK:=	${ENGINE_PKCS11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	engine-pkcs11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nengine-pkcs11}
BUILDLINK_PACKAGES+=	engine-pkcs11

.if !empty(ENGINE_PKCS11_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.engine-pkcs11+=	engine-pkcs11>=0.1.3
BUILDLINK_PKGSRCDIR.engine-pkcs11?=	../../wip/engine-pkcs11
.endif	# ENGINE_PKCS11_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
