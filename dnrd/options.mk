# $NetBSD: options.mk,v 1.1.1.1 2006/06/03 23:45:48 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dnrd
PKG_SUPPORTED_OPTIONS=	random-source-port pid-file tcp-support
PKG_SUGGESTED_OPTIONS=	pid-file

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrandom-source-port)
CONFIGURE_ARGS+=	--enable-random-src
.endif

.if empty(PKG_OPTIONS:Mpid-file)
CONFIGURE_ARGS+=	--disable-pid-file
.endif

.if !empty(PKG_OPTIONS:Mtcp-support)
CONFIGURE_ARGS+=	--enable-tcp
.endif
