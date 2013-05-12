# $NetBSD: options.mk,v 1.1 2013/05/12 01:12:32 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt-gstreamer
PKG_SUPPORTED_OPTIONS=	debug static tests # XXX doc
PKG_SUGGESTED_OPTIONS+=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
.endif

.if !empty(PKG_OPTIONS:Mstatic)
CMAKE_ARGS+=		-DQTGSTREAMER_STATIC=ON
.else
CMAKE_ARGS+=		-DQTGSTREAMER_STATIC=OFF
.endif

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=		-DQTGSTREAMER_TESTS=ON
.else
CMAKE_ARGS+=		-DQTGSTREAMER_TESTS=OFF
.endif
