# $NetBSD: Makefile,v 1.19 2022/07/03 15:59:17 wiz Exp $

GCC_PKGNAME=		gcc10
.include		"version.mk"

DISTNAME=	gcc-${GCC10_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-libjit-${GCC10_DIST_VERSION}
## When bumping the PKGREVISION of this package the PKGREVISION of
## lang/gcc10-libs needs to be bumped to be at least 1 more than the
## PKGREVISION of this package!
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC10_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) - 10.0 Release Series
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

# Relocations result in a linker error on AArch64, but not x86.
MKPIE_SUPPORTED=	no
CHECK_RELRO_SKIP+=	${GCC_PKGNAME}/lib/*

NOT_FOR_PLATFORM=	Interix-*-*

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		gmake makeinfo sed:run tar:build
USE_TOOLS.NetBSD+=	gsed

# /usr/bin/ld: ./../intl/libintl.a(bindtextdom.o): relocation R_X86_64_32 against symbol `libintl_nl_default_dirname' can not be used when making a shared object; recompile with -fPIC
CFLAGS+=	-fPIC
# ld: /usr/lib/libstdc++.a(eh_globals.o): relocation R_X86_64_TPOFF32 against `_ZZN12_GLOBAL__N_110get_globalEvE6global' can not be used when making a shared object; recompile with -fPIC
CXXFLAGS+=	-fPIC

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure
GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}
INFO_FILES=		yes
CONFIGURE_ARGS+=	--disable-libstdcxx-pch

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

CHECK_PORTABILITY_SKIP+=	contrib/*

INSTALLATION_DIRS=	lib

.include "options.mk"

## For graphite support.
.if !empty(PKG_OPTIONS:Mgcc-graphite)

post-extract:
	${TAR} -jxf ${DISTDIR}/${ISL16}.tar.bz2 -C ${WRKSRC}
	${MV} ${WRKSRC}/${ISL16} ${WRKSRC}/isl
.endif

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-languages=jit
CONFIGURE_ARGS+=	--without-static-standard-libraries
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-host-shared
CONFIGURE_ARGS.NetBSD+=	--with-gnu-ld --with-ld=/usr/bin/ld
CONFIGURE_ARGS.NetBSD+=	--with-gnu-as --with-as=/usr/bin/as
MAKE_ENV.NetBSD+=	ac_cv_func_clock_gettime=yes
MAKE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no
MAKE_ENV.NetBSD+=	ac_cv_func_freelocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_newlocale=no
MAKE_ENV.NetBSD+=	ac_cv_func_uselocale=no

MAKE_FLAGS+=		BOOT_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		BOOT_CXXFLAGS=${CXXFLAGS:Q}
MAKE_FLAGS+=		BOOT_LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS_FOR_TARGET=${LDFLAGS:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		CXXFLAGS=${CXXFLAGS:Q}

BUILD_TARGET=		all-gcc

INSTALL_DIRS=		${WRKSRC}/${OBJDIR}/gcc
INSTALL_TARGET=		jit.install-common jit.install-info

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

CHECK_BUILTIN.zlib:= yes
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.zlib:= no
.if ${USE_BUILTIN.zlib:tl} == yes
CONFIGURE_ARGS+=	--with-system-zlib
.else
CONFIGURE_ARGS+=	--without-system-zlib
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
