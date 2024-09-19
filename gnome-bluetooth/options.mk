# $NetBSD: options.mk,v 1.1 2013/02/25 01:28:34 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-bluetooth
PKG_SUPPORTED_OPTIONS=	introspection nls
PKG_SUGGESTED_OPTIONS+=	introspection nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
.include "../../devel/gobject-introspection/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-introspection=yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
