# $NetBSD: buildlink3.mk,v 1.43 2020/08/17 20:17:50 leot Exp $

BUILDLINK_TREE+=	gtk4

.if !defined(GTK4_BUILDLINK3_MK)
GTK4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk4+=	gtk4+>=3.99.0
BUILDLINK_ABI_DEPENDS.gtk4+=	gtk4+>=3.99.4
BUILDLINK_PKGSRCDIR.gtk4?=	../../wip/gtk4

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := gtk4
.include "../../mk/pkg-build-options.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.4
.include "../../graphics/libepoxy/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.gtk4:Mx11}
.  if ${PKG_BUILD_OPTIONS.gtk4:Mgtk3-atk-bridge}
.    include "../../devel/at-spi2-atk/buildlink3.mk"
.  endif # PKG_BUILD_OPTIONS.gtk4:Mgtk3-atk-bridge
.include "../../x11/libXcursor/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif # PKG_BUILD_OPTIONS.gtk4:Mx11
.if ${PKG_BUILD_OPTIONS.gtk4:Mwayland}
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif # PKG_BUILD_OPTIONS.gtk4:Mwayland
.endif # GTK4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk4
