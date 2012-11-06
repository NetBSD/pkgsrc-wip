# $NetBSD: options.mk,v 1.1 2012/11/06 16:26:15 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qcomicbook
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Debug
.endif
