# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.zig-git
PKG_SUPPORTED_OPTIONS=	debug

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mdebug}
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
.endif
