# $NetBSD: options.mk,v 1.1 2013/04/18 01:25:26 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.couchdb-glib
PKG_SUPPORTED_OPTIONS=	introspection
PKG_SUGGESTED_OPTIONS+=	introspection
PLIST_VARS+=		introspection

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mintrospection)
CONFIGURE_ARGS+=	--enable-introspection=yes
.include "../../devel/gobject-introspection/buildlink3.mk"
PLIST.introspection=	yes
.else
CONFIGURE_ARGS+=	--enable-introspection=no
.endif
