# $NetBSD: options.mk,v 1.9 2019/10/03 20:45:19 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gst-plugins1-base
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS=	introspection

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	introspection

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
MESON_ARGS+=		-D introspection=disabled
.endif
