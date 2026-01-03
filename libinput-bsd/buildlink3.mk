# $NetBSD$

BUILDLINK_TREE+=	libinput-bsd

.if !defined(LIBINPUT_BSD_BUILDLINK3_MK)
LIBINPUT_BSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinput-bsd+=	libinput-bsd>=1.26.2
BUILDLINK_PKGSRCDIR.libinput-bsd?=	../../wip/libinput-bsd

.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../wip/libevdev-openbsd/buildlink3.mk"
.include "../../devel/libudev-bsd/buildlink3.mk"
.include "../../wip/libinput-bsd-headers/buildlink3.mk"
.endif	# LIBINPUT_BSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinput-bsd
