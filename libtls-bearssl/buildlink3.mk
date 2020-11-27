# $NetBSD$

BUILDLINK_TREE+=	libtls-bearssl

.if !defined(LIBTLS_BEARSSL_BUILDLINK3_MK)
LIBTLS_BEARSSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtls-bearssl+=	libtls-bearssl>=0.2
BUILDLINK_PKGSRCDIR.libtls-bearssl?=	../../wip/libtls-bearssl
BUILDLINK_DEPMETHOD.libtls-bearssl?=	build
.endif	# LIBTLS_BEARSSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtls-bearssl
