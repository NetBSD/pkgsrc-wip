# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.wla-dx
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=	doc

.include "../../mk/bsd.options.mk"


.if !empty(PKG_OPTIONS:Mdoc)
PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-sphinx
BUILD_DEPENDS+=	py[0-9]*-sphinx-[0-9]*:../../textproc/py-sphinx
PLIST.doc=	yes
.endif
