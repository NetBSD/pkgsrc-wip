# $NetBSD: options.mk,v 1.2 2013/05/16 10:56:24 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libtifiles2
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS+=	nls
PLIST_VARS+=		nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
