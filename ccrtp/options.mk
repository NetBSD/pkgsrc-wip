# $NetBSD: options.mk,v 1.1 2013/03/26 10:45:30 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ccrtp
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
