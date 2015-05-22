# $NetBSD: options.mk,v 1.1 2015/05/22 23:49:40 krytarowski Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lxqt
PKG_SUPPORTED_OPTIONS=	openbox # alternatives: kwin and possibly metacity
PKG_SUGGESTED_OPTIONS=	openbox

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=       openbox>=3.5.2:../../wm/openbox
.endif
