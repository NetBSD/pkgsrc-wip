# $NetBSD: buildlink3.mk,v 1.3 2008/01/18 04:30:12 tnn2 Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ENGINE_PKCS11_BUILDLINK3_MK:=	${ENGINE_PKCS11_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	engine-pkcs11
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nengine-pkcs11}
BUILDLINK_PACKAGES+=	engine-pkcs11

.if !empty(ENGINE_PKCS11_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.engine-pkcs11+=	engine-pkcs11>=0.1.3
BUILDLINK_ABI_DEPENDS.engine-pkcs11?=	engine-pkcs11>=0.1.3nb1
BUILDLINK_PKGSRCDIR.engine-pkcs11?=	../../wip/engine-pkcs11
.endif	# ENGINE_PKCS11_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
