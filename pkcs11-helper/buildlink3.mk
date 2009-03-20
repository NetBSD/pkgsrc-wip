# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_DEPMETHOD.pkcs11-helper?=	build

BUILDLINK_TREE+=	pkcs11-helper

.if !defined(PKCS11_HELPER_BUILDLINK3_MK)
PKCS11_HELPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pkcs11-helper+=	pkcs11-helper>=1.06
BUILDLINK_PKGSRCDIR.pkcs11-helper?=	../../wip/pkcs11-helper
.endif # PKCS11_HELPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-pkcs11-helper
