# $NetBSD$

GCC_PKGNAME=	gcc
GCC_TARGET=	i686-elf
.include	"../../lang/gcc8/version.mk"

DISTNAME=	gcc-${GCC8_DIST_VERSION}
PKGNAME=	cross-${GCC_TARGET}-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC8_DIST_VERSION}/}
DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_USING=	bsdtar
PATCHDIR=	${.CURDIR}/../../lang/gcc8/patches
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	port-i386@NetBSD.org
HOMEPAGE=	https://gcc.gnu.org/
COMMENT=	GCC for bare metal i686 ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

# Relocations result in a linker error on AArch64, but not x86.
MKPIE_SUPPORTED=	no
CHECK_RELRO_SKIP+=	${GCC_PKGNAME}/lib/*

DEPENDS+=		cross-${GCC_TARGET}-binutils>=2.31.1:../../cross/${GCC_TARGET}-binutils

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake makeinfo sed tar:build
USE_TOOLS.NetBSD+=	gsed

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GCC_SUBPREFIX=		cross-${GCC_TARGET}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}
INFO_FILES=		yes
CONFIGURE_ARGS+=	--target=${GCC_TARGET}
# TODO: make it build with c++ enabled (--enable-languages=c,c++)
CONFIGURE_ARGS+=	--enable-languages=c
#CONFIGURE_ARGS+=	--with-sysroot
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--without-headers
# GCC is broken and tries link tests after already setting gcc_no_link=yes if it
# doesn't know the OS. Override them to no to avoid the forbidden link tests.
CONFIGURE_ARGS+=	target_configargs="gcc_cv_have_tls=no ac_cv_func_shl_load=no ac_cv_lib_dld_shl_load=no ac_cv_func_dlopen=no ac_cv_lib_dl_dlopen=no ac_cv_lib_svld_dlopen=no ac_cv_lib_dld_dld_link=no"

# TODO: make it build past "checking for the value of EOF... configure: error: computing EOF failed"
# https://stackoverflow.com/questions/72750342/gcc-cross-compiler-make-vs-make-all-gcc-why-does-one-give-me-an-error-but-the-o
BUILD_TARGET=		all-gcc all-target-libgcc
INSTALL_TARGET=		install-gcc install-target-libgcc

CHECK_PORTABILITY_SKIP+=	contrib/*

.include "../../mk/bsd.prefs.mk"

#post-extract:
#	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
#	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

.if ${MACHINE_PLATFORM:MNetBSD-*-*}
# on NetBSD, use the native SSP code in libc
CONFIGURE_ARGS+=	--disable-libssp
# Match base libstdc++ major
SUBST_CLASSES+=		libstdc
SUBST_STAGE.libstdc=	pre-configure
SUBST_FILES.libstdc=	libstdc++-v3/configure
SUBST_MESSAGE.libstdc=	Bumping libstdc++ major to 7
SUBST_SED.libstdc=	-e 's,libtool_VERSION=6:,libtool_VERSION=7:,g'
.else
CONFIGURE_ARGS+=	--enable-libssp
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}


CHECK_BUILTIN.zlib:=	yes
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.zlib:=	no
.if ${USE_BUILTIN.zlib:tl} == yes
CONFIGURE_ARGS+=	--with-system-zlib
.include "../../devel/zlib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-system-zlib
.endif
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
