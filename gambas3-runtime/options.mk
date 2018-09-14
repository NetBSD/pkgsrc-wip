# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gambas3-runtime
PKG_SUPPORTED_OPTIONS=	qt4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt4)
BUILD_DEPENDS+=	gambas3-gb-qt4-opengl-${GB_VERSION}:../../wip/gambas3-gb-qt4-opengl
BUILD_DEPENDS+=	gambas3-gb-qt4-webkit-${GB_VERSION}:../../wip/gambas3-gb-qt4-webkit
.endif
