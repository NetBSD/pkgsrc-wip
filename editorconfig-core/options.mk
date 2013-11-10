# $NetBSD: options.mk,v 1.1 2013/11/10 21:04:48 nros Exp $
PKG_OPTIONS_VAR=	PKG_OPTIONS.editorconfig-core
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=	doc
PLIST_VARS+=		doc

.include "../../mk/bsd.options.mk"

###
### Build and install html documentation and man pages
###
.if !empty(PKG_OPTIONS:Mdoc)
BUILD_DEPENDS+= doxygen:../../devel/doxygen
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=ON
CMAKE_ARGS+=    -DINSTALL_HTML_DOC=ON
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DBUILD_DOCUMENTATION=OFF
.endif
