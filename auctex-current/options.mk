# $NetBSD: options.mk,v 1.1.1.1 2010/10/13 13:06:29 makoto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.auctex_current
PKG_SUPPORTED_OPTIONS=	ja-ptex
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mja-ptex)
DEPENDS+=		ja-ptex:../../print/ja-ptex
.else
DEPENDS+=		teTeX:../../print/teTeX
# tex-latex-bin and tex-graphics ?
.endif
