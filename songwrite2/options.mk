# $NetBSD: options.mk,v 1.1 2012/12/31 23:38:01 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.songwrite2
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
BUILD_OPTIONS+=		--debug
.endif
