# $NetBSD: options.mk,v 1.10 2014/09/21 01:08:27 makoto Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.gnuradio
PKG_SUPPORTED_OPTIONS=  ninja

# Adding ninja to following line (now) stops
# [164/850] cd /PATH/wip/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# FAILED: cd /PATH/wip/gnuradio-core/work/gnuradio-3.7.5/build/gr-audio/swig && ""
# : permission denied

PKG_SUGGESTED_OPTIONS=  

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mninja)
CMAKE_ARGS+=	-GNinja
BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

do-build:
	(cd ${WRKSRC}/build; ninja)
.else
do-build:
	(cd ${WRKSRC}/build; ${GMAKE})
.endif
