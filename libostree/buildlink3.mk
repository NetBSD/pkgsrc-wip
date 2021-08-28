# $NetBSD$

BUILDLINK_TREE+=	libostree

.if !defined(LIBOSTREE_BUILDLINK3_MK)
LIBOSTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libostree+=	libostree>=2021.3
BUILDLINK_PKGSRCDIR.libostree?=		../../wip/libostree

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBOSTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libostree
