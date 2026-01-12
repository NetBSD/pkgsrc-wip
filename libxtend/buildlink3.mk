# $NetBSD$

BUILDLINK_TREE+=		libxtend

.if !defined(LIBXTEND_BUILDLINK3_MK)
LIBXTEND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxtend+=	libxtend>=0.2.1.12
BUILDLINK_PKGSRCDIR.libxtend?=		../../wip/libxtend
.endif	# LIBXTEND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxtend
