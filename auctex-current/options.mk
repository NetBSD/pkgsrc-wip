# $NetBSD: options.mk,v 1.2 2012/11/17 10:35:17 kristerw Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.auctex_current
PKG_SUPPORTED_OPTIONS=	ja-ptex
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mja-ptex)
DEPENDS+=		ja-ptex-[0-9]*:../../print/ja-ptex
.else
DEPENDS+=		teTeX-[0-9]*:../../print/teTeX
# tex-latex-bin and tex-graphics ?
.endif
