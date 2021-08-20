# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.avr-gcc
PKG_SUPPORTED_OPTIONS=	gcc-inplace-math gcc-graphite
PKG_SUGGESTED_OPTIONS=	gcc-graphite

.include "../../mk/bsd.options.mk"

# gcc-inplace-math: Build math libraries in place
.if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.  include "../../devel/gmp/inplace.mk"
.  include "../../math/mpcomplex/inplace.mk"
.  include "../../math/mpfr/inplace.mk"
.else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
.  include "../../devel/gmp/buildlink3.mk"
.  include "../../math/mpcomplex/buildlink3.mk"
.  include "../../math/mpfr/buildlink3.mk"
.endif

# gcc-graphite: Enable Graphite support
.if !empty(PKG_OPTIONS:Mgcc-graphite)
ISL2X=			isl-0.24
SITES.${ISL2X}.tar.bz2=	http://isl.gforge.inria.fr/
DISTFILES+=		${ISL2X}.tar.bz2
.endif
