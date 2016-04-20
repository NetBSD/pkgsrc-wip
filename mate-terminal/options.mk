# $NetBSD: options.mk,v 1.3 2015/04/09 02:56:30 krytarowski Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-terminal
PKG_SUPPORTED_OPTIONS=	skey
PKG_SUGGESTED_OPTIONS=	skey

PLIST_VARS+=	skey

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--enable-skey
PLIST.skey=		yes
.else
CONFIGURE_ARGS+=	--disable-skey
.endif
