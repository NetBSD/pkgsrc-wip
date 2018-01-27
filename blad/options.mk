# $NetBSD: options.mk,v 1.6 2013/08/01 18:44:06 riastradh Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.blad
PKG_SUPPORTED_OPTIONS=		gmp mpfr sage gsl
PKG_SUGGESTED_OPTIONS=		gmp
PKG_OPTIONS_OPTIONAL_GROUPS=	math
PKG_OPTIONS_GROUP.math=		gmp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgmp)
.include "../../devel/gmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gmp
.endif

.if !empty(PKG_OPTIONS:Mmpfr)
BUILDLINK_API_DEPENDS.mpfr+=    mpfr>=2.0.3
.include "../../math/mpfr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mpfr
.endif

.if !empty(PKG_OPTIONS:Mgsl)
.include "../../math/gsl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gsl
.endif

.if !empty(PKG_OPTIONS:Msage)
CONFIGURE_ARGS+=	--enable-sage
.endif
