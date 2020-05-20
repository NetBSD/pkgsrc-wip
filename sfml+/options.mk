# $NetBSD: options.mk,v 1.1 2012/10/03 15:05:59 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sfml+
PKG_SUPPORTED_OPTIONS=	debug static
PKG_SUGGESTED_OPTIONS=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
MAKE_ENV+=		DEBUGBUILD=yes
.else
MAKE_ENV+=		DEBUGBUILD=no
.endif

.if !empty(PKG_OPTIONS:Mstatic)
MAKE_ENV+=		STATIC=yes
.else
MAKE_ENV+=		STATIC=no
.endif
