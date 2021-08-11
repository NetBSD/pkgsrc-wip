# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.avr-gcc
PKG_SUPPORTED_OPTIONS=	gcc-inplace-math gcc-graphite
PKG_SUGGESTED_OPTIONS=

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
ISL16=			isl-0.16.1
SITES.${ISL16}.tar.bz2=	${MASTER_SITE_GNU:=gcc/infrastructure/}
DISTFILES+=		${ISL16}.tar.bz2
.endif
