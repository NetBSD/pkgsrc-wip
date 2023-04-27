# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-pynitrokey

PKG_SUPPORTED_OPTIONS+=		doc

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mdoc}
DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
# else switch this off in cmake
.endif
