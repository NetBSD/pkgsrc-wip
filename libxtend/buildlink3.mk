# $NetBSD$

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libxtend?=	build

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.0.1.13
BUILDLINK_PKGSRCDIR.libxtend?=		../../wip/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
