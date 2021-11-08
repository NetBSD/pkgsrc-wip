# $NetBSD: options.mk,v 1.9 2019/10/03 20:45:19 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gst-plugins1-base
PKG_SUPPORTED_OPTIONS=		alsa introspection x11

PKG_SUGGESTED_OPTIONS=		introspection

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=		alsa x11
.elif ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		x11
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=		yes
.else
MESON_ARGS+=		-D alsa=disabled
.endif

PLIST_VARS+=	introspection
.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=		-D introspection=disabled
.endif

PLIST_VARS+=	opengl
.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
PLIST.opengl=		yes
MESON_ARGS+=		-D gl_winsys=x11
.else
MESON_ARGS+=		-D gl=disabled
.endif

PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
PLIST.x11=		yes
.else
MESON_ARGS+=		-D xshm=disabled
MESON_ARGS+=		-D xvideo=disabled
MESON_ARGS+=		-D x11=disabled
.endif
