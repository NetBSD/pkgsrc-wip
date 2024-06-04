# $NetBSD: options.mk,v 1.3 2024/05/02 06:50:00 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icewm3
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !${PKG_OPTIONS:Mnls}
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST.nls=		yes
.endif
