# $NetBSD$

BUILDLINK_TREE+=	libevdev-openbsd

.if !defined(LIBEVDEV_OPENBSD_BUILDLINK3_MK)
LIBEVDEV_OPENBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libevdev-openbsd+=	libevdev-openbsd>=20231111
BUILDLINK_PKGSRCDIR.libevdev-openbsd?=		../../wip/libevdev-openbsd

.include "../../wip/libinput-bsd-headers/buildlink3.mk"
.endif	# LIBEVDEV_OPENBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libevdev-openbsd
