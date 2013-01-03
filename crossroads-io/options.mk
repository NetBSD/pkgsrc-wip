# $NetBSD: options.mk,v 1.1 2013/01/03 03:38:48 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.crossroads-io
PKG_SUPPORTED_OPTIONS=	debug doc
PKG_SUGGESTED_OPTIONS+=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--without-documentation
.endif
