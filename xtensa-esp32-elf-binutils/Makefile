# $NetBSD$

DISTNAME=		espressif-binutils-gdb-${GITHUB_TAG}
PKGNAME=		xtensa-esp32-elf-binutils-2.45.0
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=espressif/}
GITHUB_PROJECT=		binutils-gdb
GITHUB_TAG=		esp-2.45.0_20251204

# Espressif overlays
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	${CROSSTOOLSRC}.tar.xz
CROSSTOOLVER=	esp-15.2.0_20251204
CROSSTOOLSRC=	crosstool-NG-${CROSSTOOLVER}-src
SITES.${CROSSTOOLSRC}.tar.xz=	-https://github.com/espressif/crosstool-NG/releases/download/${CROSSTOOLVER}/${CROSSTOOLSRC}.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espressif/binutils-gdb
COMMENT=	Cross binutils for Espressif ESP32 target
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

INFO_FILES=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo bison perl
USE_LANGUAGES+=		c c++
MKPIE_SUPPORTED=	no	# strange errors with libiberty. checking for fcntl.h ... no

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp32-elf

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=xtensa-esp32-elf
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-gdb

CHECK_SHLIBS_SKIP+=		xtensa-esp32-elf/lib/xtensa*.so
CHECK_PORTABILITY_SKIP+=	sim/testsuite/bfin/run-tests.sh

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	bfd/xtensa-dynconfig.c
SUBST_STAGE.prefix=	 pre-configure
SUBST_MESSAGE.prefix=	Substitute GNU_CONFIGURE_PREFIX in patch
SUBST_VARS.prefix+=	GNU_CONFIGURE_PREFIX

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-extract:
	${CP} -r ${WRKDIR}/${CROSSTOOLSRC}/overlays/xtensa_esp32/binutils/. ${WRKSRC}/.

pre-build:
	${RUN} cd ${WRKDIR}/${CROSSTOOLSRC}/xtensa-dynconfig && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} CONF_DIR=${WRKDIR}/${CROSSTOOLSRC}/overlays

post-install:
	set -e; for f in ${WRKDIR}/${CROSSTOOLSRC}/xtensa-dynconfig/*.so; do	\
		${INSTALL_PROGRAM} $$f ${DESTDIR}${GNU_CONFIGURE_PREFIX}/lib;				\
	done

.include "../../mk/bsd.pkg.mk"
