# $NetBSD$


BUILDLINK_TREE+=	cinnamon-desktop

.if !defined(CINNAMON_DESKTOP_BUILDLINK3_MK)
CINNAMON_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-desktop+=	cinnamon-desktop>=4.6.4
BUILDLINK_ABI_DEPENDS.cinnamon-desktop?=	cinnamon-desktop>=4.6.4nb1
BUILDLINK_PKGSRCDIR.cinnamon-desktop?=	../../wip/cinnamon-desktop

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.endif	# CINNAMON_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-desktop
