# $NetBSD$

BUILDLINK_TREE+=	libkscreen

.if !defined(LIBKSCREEN_BUILDLINK3_MK)
LIBKSCREEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkscreen+=	libkscreen>=6.0.5
BUILDLINK_PKGSRCDIR.libkscreen?=	../../wip/libkscreen-qt6

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../wip/kwayland-qt6/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKSCREEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkscreen
