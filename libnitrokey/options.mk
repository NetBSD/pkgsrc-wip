# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.py-pynitrokey

PKG_SUPPORTED_OPTIONS+=		doc tests

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mdoc}
DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
# else switch this off in cmake
.endif

.if ${PKG_OPTIONS:Mtests}
# These tests do not require any device to be connected
CMAKE_ARGS+=	-DCOMPILE_OFFLINE_TESTS=ON
TEST_DEPENDS+=	catch2-[0-9]*:../../devel/catch2
.endif
