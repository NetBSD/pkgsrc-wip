# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.eureka-devel
PKG_SUPPORTED_OPTIONS=	xdg-utils
PKG_SUGGESTED_OPTIONS=	xdg-utils

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# xdg-utils: Create dependency for xdg-utils (Portland project)
# xdg-utils are used for WWW-Browser and eMail redirection
.if !empty(PKG_OPTIONS:Mxdg-utils)
DEPENDS+=	xdg-utils>=1.1:../../misc/xdg-utils
.endif
