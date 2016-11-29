# $NetBSD: options.mk,v 1.32 2016/08/20 11:17:32 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.chromium
PKG_SUPPORTED_OPTIONS+=	debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
BUILDTYPE=	Debug
GN_ARGS+=	is_debug=true
# Dynamic link build causes link errors in pkgsrc.
GN_ARGS+=	is_component_build=false
GN_BOOTSTRAP_FLAGS+=	--debug
#GN_VERBOSE=    -v
.else
BUILDTYPE=	Release
GN_ARGS+=	is_debug=false \
		symbol_level=0 \
		remove_webcore_debug_symbols=true
.endif
