# $NetBSD$

BUILDLINK_DEPMETHOD.boringssl?=	build
BUILDLINK_TREE+=		boringssl

.if !defined(BORINGSSL_BUILDLINK3_MK)
BORINGSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.boringssl+=	boringssl>=20151230nb6
BUILDLINK_PKGSRCDIR.boringssl?=		../../wip/boringssl
.endif	# BORINGSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-boringssl
