# $NetBSD$

BUILDLINK_TREE+=	cinnamon-desktop

.if !defined(CINNAMON_DESKTOP_BUILDLINK3_MK)
CINNAMON_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.cinnamon-desktop?=	build

BUILDLINK_API_DEPENDS.cinnamon-desktop+=	cinnamon-desktop>=4.0.0
BUILDLINK_PKGSRCDIR.cinnamon-desktop?=	../../wip/cinnamon-desktop

.include "../../audio/pulseaudio/buildlink3.mk""
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.endif	# CINNAMON_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-desktop
