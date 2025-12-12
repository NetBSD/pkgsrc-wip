# $NetBSD$

DISTNAME=	espressif-gcc-15.2.0-${GITHUB_TAG}
PKGNAME=	xtensa-esp32-elf-gcc-15.2.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=	gcc
GITHUB_TAG=	esp-15.2.0_20251204
# Espressif overlays
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${CROSSTOOLSRC}.tar.xz
CROSSTOOLVER=	esp-15.2.0_20251204
CROSSTOOLSRC=	crosstool-NG-${CROSSTOOLVER}-src
SITES.${CROSSTOOLSRC}.tar.xz=	\
	-https://github.com/espressif/crosstool-NG/releases/download/${CROSSTOOLVER}/${CROSSTOOLSRC}.tar.xz

# Custom ESP32 newlib
DISTFILES+=	newlib-${NEWLIBVER}.tar.gz
NEWLIBVER=	esp-4.5.0_20251204
SITES.newlib-${NEWLIBVER}.tar.gz= \
	-https://github.com/espressif/newlib-esp32/archive/refs/tags/${NEWLIBVER}.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/espressif/gcc
COMMENT=		Cross GCC for Espressif ESP32 target
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DEPENDS+=	xtensa-esp32-elf-binutils>=2.41.0:../../wip/xtensa-esp32-elf-binutils

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c c++
USE_TOOLS+=		bash gmake gsed makeinfo perl

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp32-elf
MKPIE_SUPPORTED=	no

CONFIGURE_ENV+=		CFLAGS_FOR_TARGET="-mlongcalls"
# This is based on "gcc -v" output from the binary release
CONFIGURE_ARGS+=	--target=xtensa-esp32-elf
CONFIGURE_ARGS+=	--exec_prefix=${GNU_CONFIGURE_PREFIX}
CONFIGURE_ARGS+=	--with-local-prefix=${GNU_CONFIGURE_PREFIX}/xtensa-esp32-elf
CONFIGURE_ARGS+=	--with-sysroot=${GNU_CONFIGURE_PREFIX}/xtensa-esp32-elf
CONFIGURE_ARGS+=	--with-native-system-header-dir=/nonexistent/include
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-threads=no
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--with-pkgversion="${PKGNAME} (pkgsrc)"
CONFIGURE_ARGS+=	--disable-__cxa_atexit
CONFIGURE_ARGS+=	--enable-cxx-flags=-ffunction-sections
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libmpx
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libquadmath-support
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-isl=${BUILDLINK_PREFIX.isl}
CONFIGURE_ARGS+=	--enable-lto
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--without-long-double-128
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-multiarch
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--enable-gcov-custom-rtio
CONFIGURE_ARGS+=	--enable-libstdcxx-time=yes
CONFIGURE_ARGS+=	--enable-multilib

CONFIGURE_ARGS+=	--disable-bootstrap

# configry for newlib
CONFIGURE_ARGS+=	--disable-newlib-io-c99-formats
CONFIGURE_ARGS+=	--disable-newlib-supplied-syscalls
CONFIGURE_ARGS+=	--enable-newlib-nano-formatted-io
CONFIGURE_ARGS+=	--enable-newlib-reent-small
CONFIGURE_ARGS+=	--enable-target-optspace
CONFIGURE_ARGS+=	--enable-newlib-nano-malloc
CONFIGURE_ARGS+=	--enable-newlib-retargetable-locking
CONFIGURE_ARGS+=	--disable-newlib_wide_orient
CONFIGURE_ARGS+=	--enable-newlib-iconv
CONFIGURE_ARGS+=	--enable-newlib-reent-binary-compat

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/configure	# CONFIG_SHELL is bash
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	gcc/config/xtensa/xtensa-dynconfig.cc
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Substitute GNU_CONFIGURE_PREFIX in patch
SUBST_VARS.prefix+=	GNU_CONFIGURE_PREFIX

ESP32_TYPE=	esp32

post-extract:
	mv ${WRKDIR}/newlib-*/newlib ${WRKSRC}/newlib
	mv ${WRKDIR}/newlib-*/libgloss ${WRKSRC}/libgloss
	${CP} -r ${WRKDIR}/${CROSSTOOLSRC}/overlays/xtensa_${ESP32_TYPE}/gcc/. ${WRKSRC}/.
	${CP} -r ${WRKDIR}/${CROSSTOOLSRC}/overlays/xtensa_${ESP32_TYPE}/newlib/. ${WRKSRC}/.

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/isl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
