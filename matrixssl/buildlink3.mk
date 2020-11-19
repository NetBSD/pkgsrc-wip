# $NetBSD$

BUILDLINK_TREE+=	matrixssl

.if !defined(MATRIXSSL_BUILDLINK3_MK)
MATRIXSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.matrixssl+=	matrixssl>=3.9.3
BUILDLINK_PKGSRCDIR.matrixssl?=		../../wip/matrixssl
BUILDLINK_INCDIRS.matrixssl+=		include/matrixssl
BUILDLINK_LIBDIRS.matrixssl+=		lib/matrixssl
BUILDLINK_DEPMETHOD.matrixssl?=		build
.endif	# MATRIXSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-matrixssl
