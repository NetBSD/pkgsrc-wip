# $NetBSD: Makefile,v 1.6 2015/03/07 21:14:32 tnn Exp $

DISTNAME=	libretro-pcsx-rearmed-20170901
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

GITHUB_PROJECT=	pcsx_rearmed
GITHUB_TAG=	09d454e73bc251b44848abba4026efcd452df752

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.libretro.com/index.php?title=PCSX_ReARMed
COMMENT=	Libretro core based on the PCSX ReARMed emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

MAKE_FLAGS+=	LIBPTHREAD="${PTHREAD_LIBS}"
MAKE_FLAGS+=	EXTRA_LDFLAGS="${PTHREAD_LDFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.if !empty(MACHINE_ARCH:M*arm*)
# only ARM-specific options for now, and options framework
# insists on having at least one option, so only pull it in for ARM
.include "options.mk"
CFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	ARCH=arm
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/pcsx_rearmed_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/pcsx_rearmed_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
