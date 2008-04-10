# $NetBSD: options.mk,v 1.1.1.1 2008/04/10 01:54:31 hitscan Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.JavaScript-SpiderMonkey
PKG_SUPPORTED_OPTIONS=	e4x
PKG_SUGGESTED_OPTIONS=	e4x

.include "../../mk/bsd.options.mk"

# E4X - ECMAScript for XML support
.if !empty(PKG_OPTIONS:Me4x)
MAKE_PARAMS+=	-E4X
.endif
