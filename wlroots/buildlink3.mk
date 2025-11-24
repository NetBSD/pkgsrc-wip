# $NetBSD$

BUILDLINK_TREE+=	wlroots

.if !defined(WLROOTS_BUILDLINK3_MK)
WLROOTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wlroots+=	wlroots>=0.10.0
BUILDLINK_PKGSRCDIR.wlroots?=	../../wip/wlroots

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
PREFER.MesaLib=	pkgsrc	# glesv2
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libdisplay-info/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-errors/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"

.include "../../wip/vulkan-loader/buildlink3.mk"
.include "../../wip/libudev-bsd/buildlink3.mk"
.include "../../wip/seatd/buildlink3.mk"
.include "../../wip/libliftoff/buildlink3.mk"
.include "../../wip/libopeninput/buildlink3.mk"

.endif	# WLROOTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wlroots
