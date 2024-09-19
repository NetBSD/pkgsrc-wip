# $NetBSD$

BUILDLINK_TREE+=	wlroots

.if !defined(WLROOTS_BUILDLINK3_MK)
WLROOTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wlroots+=	wlroots>=0.10.0
BUILDLINK_PKGSRCDIR.wlroots?=	../../wip/wlroots

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.endif	# WLROOTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wlroots
