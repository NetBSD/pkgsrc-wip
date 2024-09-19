# $NetBSD: options.mk,v 1.2 2014/12/10 06:10:46 keckhardt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.${GCC_PKGNAME}
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran \
			gcc-go gcc-d gcc-objc gcc-objc++ gcc-graphite
PKG_SUGGESTED_OPTIONS=	gcc-c++ gcc-fortran gcc-objc gcc-objc++ \
			gcc-graphite gcc-inplace-math

PKG_SUGGESTED_OPTIONS.NetBSD=		nls
PKG_SUGGESTED_OPTIONS.Linux=		nls
PKG_SUGGESTED_OPTIONS.DragonFly=	nls
PKG_SUGGESTED_OPTIONS.SunOS=		gcc-inplace-math
PKG_SUGGESTED_OPTIONS+=			${PKG_SUGGESTED_OPTIONS.${OPSYS}}

###
### Determine if multilib is available.
###
MULTILIB_SUPPORTED?=	unknown
.if ${MACHINE_PLATFORM:MLinux-*-x86_64}
.  if exists(/usr/include/gnu/stubs-64.h) && \
     !exists(/usr/include/gnu/stubs-32.h)
MULTILIB_SUPPORTED=	No
.  else
MULTILIB_SUPPORTED=	Yes
.  endif
.endif
.if ${MULTILIB_SUPPORTED:tl} == yes
PKG_SUPPORTED_OPTIONS+=	gcc-multilib
PKG_SUGGESTED_OPTIONS+=	gcc-multilib
.endif

.include "../../mk/bsd.options.mk"

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
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
ISL16=			isl-0.16.1
SITES.${ISL16}.tar.bz2=	${MASTER_SITE_GNU:=gcc/infrastructure/}
DISTFILES+=		${ISL16}.tar.bz2
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc++)
.  if empty(PKG_OPTIONS:Mgcc-c++)
PKG_OPTIONS+=		gcc-c++
.  endif
.  if empty(PKG_OPTIONS:Mgcc-objc)
PKG_OPTIONS+=		gcc-objc
.  endif
LANGS+=			obj-c++
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc)
LANGS+=			objc
.endif

.if !empty(PKG_OPTIONS:Mgcc-d)
LANGS+=			d
.endif

USE_TOOLS+=		unzip zip:run gmake:run
CONFIGURE_ARGS+=	--with-system-zlib

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"

.if !empty(PKG_OPTIONS:Mgcc-go)
LANGS+=			go
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
LANGS+=			fortran
.endif

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=			c++
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-__cxa_atexit
CONFIGURE_ARGS+=	--with-gxx-include-dir=${GCC_PREFIX}/include/c++/
.else
CONFIGURE_ARGS+=	--disable-build-with-cxx
CONFIGURE_ARGS+=	--disable-build-poststage1-with-cxx
.endif
