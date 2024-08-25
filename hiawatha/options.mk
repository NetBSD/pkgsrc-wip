# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.hiawatha
PKG_SUPPORTED_OPTIONS=		monitor tomahawk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmonitor)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MONITOR=on
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_MONITOR=off
.endif

.if !empty(PKG_OPTIONS:Mtomahawk)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TOMAHAWK=on
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_TOMAHAWK=off
.endif
