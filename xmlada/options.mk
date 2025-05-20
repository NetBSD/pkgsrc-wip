# $NetBSD: options.mk,v 1.1 2025/05/09 16:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xmlada
PKG_OPTIONS_OPTIONAL_GROUPS=	shared-libs
PKG_OPTIONS_GROUP.shared-libs=	enable-shared-libs disable-shared-libs

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-shared-libs)
CONFIGURE_ARGS+=	--enable-shared
USE_GCC_RUNTIME=	yes
.endif
.if !empty(PKG_OPTIONS:Mdisable-shared-libs)
CONFIGURE_ARGS+=	--disable-shared
.endif
.if empty(PKG_OPTIONS:Menable-shared-libs) && empty(PKG_OPTIONS:Mdisable-shared-libs)
USE_GCC_RUNTIME=	yes
.endif
