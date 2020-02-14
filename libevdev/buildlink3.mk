# $NetBSD$

BUILDLINK_TREE+=	libevdev

.if !defined(LIBEVDEV_BUILDLINK3_MK)
LIBEVDEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevdev+=	libevdev>=1.8.0
BUILDLINK_PKGSRCDIR.libevdev?=		../../wip/libevdev
.endif # LIBEVDEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevdev
