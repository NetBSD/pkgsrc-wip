# $NetBSD$

DISTNAME=		gcc-12.2.0
PKGNAME=		cross-riscv64-none-elf-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		cross
NEWLIBVER=		4.3.0.20230120
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		port-riscv@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal Riscv64
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

EXTRACT_USING=		bsdtar

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=          gtexinfo>=5.1:../../devel/gtexinfo
TOOLS_USE_PKGSRC.makeinfo= yes

DEPENDS+=		cross-riscv64-none-elf-binutils-[0-9]*:../../cross/riscv64-none-elf-binutils

USE_LANGUAGES+=		c c++

RISCV64ELF_PREFIX=	${PREFIX}/cross-riscv64-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh
CHECK_PORTABILITY_SKIP+=	gcc/configure

GNU_CONFIGURE_PREFIX=	${RISCV64ELF_PREFIX}

CONFIGURE_ARGS+= --target=riscv64-none-elf
CONFIGURE_ARGS+= --enable-languages=c,c++
CONFIGURE_ARGS+= --with-abi=lp64d
CONFIGURE_ARGS+= --with-newlib
CONFIGURE_ARGS+= --disable-libgomp
CONFIGURE_ARGS+= --enable-obsolete
CONFIGURE_ARGS+= --enable-secureplt
CONFIGURE_ARGS+= --disable-werror
CONFIGURE_ARGS+= --with-system-zlib
CONFIGURE_ARGS+= --enable-nls
CONFIGURE_ARGS+= --without-included-gettext
CONFIGURE_ARGS+= --disable-libunwind-exceptions
CONFIGURE_ARGS+= --enable-checking=release
CONFIGURE_ARGS+= --with-gcc-major-version-only
CONFIGURE_ARGS+= --disable-esp
CONFIGURE_ARGS+= --enable-lto
CONFIGURE_ARGS+= --disable-libstdcxx-pch
CONFIGURE_ARGS+= --enable-poison-system-directories
CONFIGURE_ARGS+= --disable-bootstrap
CONFIGURE_ARGS+= --enable-__cxa_atexit
CONFIGURE_ARGS+= --enable-clocale=gnu
CONFIGURE_ARGS+= --disable-multilib
CONFIGURE_ARGS+= --disable-fixed-point
CONFIGURE_ARGS+= --disable-libssp
CONFIGURE_ARGS+= --disable-libada
CONFIGURE_ARGS+= --disable-cet
CONFIGURE_ARGS+= --disable-systemtap
CONFIGURE_ARGS+= --disable-valgrind-annotations
CONFIGURE_ARGS+= --disable-vtable-verify
CONFIGURE_ARGS+= --disable-libvtv
CONFIGURE_ARGS+= --without-zstd
CONFIGURE_ARGS+= --without-isl
CONFIGURE_ARGS+= --disable-libsanitizer
CONFIGURE_ARGS+= --enable-default-pie
CONFIGURE_ARGS+= --enable-default-ssp

INFO_FILES=		yes

PLIST_VARS+=		libcpp

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "Darwin"
PLIST.libcpp=	yes
.endif

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

