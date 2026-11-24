# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.guile-hoot
PKG_SUPPORTED_OPTIONS=	server
PKG_SUGGESTED_OPTIONS=	server

.include "../../mk/bsd.options.mk"

###
###  Include server support
###
.if !empty(PKG_OPTIONS:Mserver)
DEPENDS+=	guile-fibers>=2.0.0:../../wip/guile-fibers
DEPENDS+=	guile-websocket>=0.3.0:../../wip/guile-websockets
PLIST.server=	yes
.endif
