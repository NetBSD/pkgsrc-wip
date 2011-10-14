# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/14 01:26:27 makoto Exp $

BUILDLINK_TREE+=	libfs

.if !defined(LIBFS_BUILDLINK3_MK)
LIBFS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfs+=	libfs>=1.0
BUILDLINK_PKGSRCDIR.libfs?=	../../wip/libfs
.endif # LIBFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfs
