# $NetBSD$

BUILDLINK_TREE+=	libevdev-chunk

.if !defined(LIBEVDEV_CHUNK_BUILDLINK3_MK)
LIBEVDEV_CHUNK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevdev-chunk+=	libevdev-chunk>=20231111
BUILDLINK_ABI_DEPENDS.libevdev-chunk+=	libevdev-chunk>=20231111
BUILDLINK_PKGSRCDIR.libevdev-chunk?=	../../wip/libevdev-chunk

.endif # LIBEVDEV_CHUNK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevdev-chunk
