# $NetBSD$

BUILDLINK_TREE+=	libinput

.if !defined(LIBINPUT_BUILDLINK3_MK)
LIBINPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libinput+=	libinput>=0.8.0
BUILDLINK_PKGSRCDIR.libinput?=		../../wip/libinput

.include "../../wip/libevdev/buildlink3.mk"
.include "../../wip/libudev/buildlink3.mk"
.include "../../wip/mtdev/buildlink3.mk"
.endif # LIBINPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinput
