# $NetBSD: options.mk,v 1.1.1.1 2006/07/14 10:43:15 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-utils
PKG_SUPPORTED_OPTIONS=	dbh
PKG_SUGGESTED_OPTIONS=	dbh

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbh)
CONFIGURE_ARGS+=	--enable-dbh
.else
CONFIGURE_ARGS+=	--disable-dbh
.endif
