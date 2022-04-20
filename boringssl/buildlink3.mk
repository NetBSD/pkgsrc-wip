# $NetBSD$

BUILDLINK_TREE+=		boringssl

.if !defined(BORINGSSL_BUILDLINK3_MK)
BORINGSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boringssl+=	boringssl>=20220419

BUILDLINK_PKGSRCDIR.boringssl?=		../../wip/boringssl
BUILDLINK_DEPMETHOD.boringssl?=		build
.endif	# BORINGSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-boringssl
