# $NetBSD: options.mk,v 1.1 2025/04/27 12:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc15-aux
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-graphite
PKG_SUGGESTED_OPTIONS=	gcc-graphite

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "NetBSD"
#PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math
.endif

###
### Determine if multilib is avalible.
###
MULTILIB_SUPPORTED?=	unknown
.if ${MACHINE_PLATFORM:MLinux-*-x86_64}
.  if exists(/usr/include/x86_64-linux-gnu/gnu)
_GNU_INCLUDE_DIR=	/usr/include/x86_64-linux-gnu/gnu
.  else
_GNU_INCLUDE_DIR=	/usr/include/gnu
.  endif
.  if exists(${_GNU_INCLUDE_DIR}/stubs-64.h) && \
     !exists(${_GNU_INCLUDE_DIR}/stubs-32.h)
MULTILIB_SUPPORTED=	No
.  else
MULTILIB_SUPPORTED=	Yes
.  endif
.endif
.if !empty(MULTILIB_SUPPORTED:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+=	gcc-multilib
PKG_SUGGESTED_OPTIONS+=	gcc-multilib
.endif

.include "../../mk/bsd.options.mk"

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
BUILDLINK_API_DEPENDS.iconv+=	libiconv>=1.17
#PREFER.iconv=	pkgsrc
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.14.5
#PREFER.gettext=	pkgsrc
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### Multilib Support
###
.if (!empty(MULTILIB_SUPPORTED:M[Yy][Ee][Ss]) && \
      empty(PKG_OPTIONS:Mgcc-multilib) ) || \
    !empty(MULTILIB_SUPPORTED:M[Nn][Oo])
CONFIGURE_ARGS+=	--disable-multilib
.endif

###
### Build math libraries in place
###
BUILDLINK_API_DEPENDS.gmp+=		gmp>=4.3.2
BUILDLINK_API_DEPENDS.mpcomplex+=	mpcomplex>=1.0.1
BUILDLINK_API_DEPENDS.mpfr+=		mpfr>=3.1.0
.if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.  include "../../devel/gmp/inplace.mk"
.  include "../../math/mpcomplex/inplace.mk"
.  include "../../math/mpfr/inplace.mk"
.else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
LIBS.SunOS+=		-lgmp

.  include "../../devel/gmp/buildlink3.mk"
.  include "../../math/mpcomplex/buildlink3.mk"
.  include "../../math/mpfr/buildlink3.mk"
.endif

###
### Graphite Support
###
.if !empty(PKG_OPTIONS:Mgcc-graphite)
BUILDLINK_API_DEPENDS.isl+=	isl>=0.15
.  if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.    include "../../math/isl/inplace.mk"
FORCE_CXX_STD=	c++17
.  else
.    include "../../math/isl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-isl=${BUILDLINK_PREFIX.isl}
.  endif
.endif
