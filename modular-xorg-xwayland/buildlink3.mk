# $NetBSD$

BUILDLINK_TREE+=	modular-xorg-xwayland

.if !defined(MODULAR_XORG_XWAYLAND_BUILDLINK3_MK)
MODULAR_XORG_XWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.modular-xorg-xwayland+=	modular-xorg-xwayland>=24.1.8
BUILDLINK_PKGSRCDIR.modular-xorg-xwayland?=	../../wip/modular-xorg-xwayland

.endif	# MODULAR_XORG_XWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-xwayland
