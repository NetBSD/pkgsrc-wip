# $NetBSD$

DISTNAME=	libretro-desmume-20170211
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/desmume/
COMMENT=	Libretro core based on the Desmume Nintendo DS emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	desmume
GITHUB_TAG=	63ed05bbf02fa841adbdfd158cdc96033b48ddc0

WRKSRC=		${WRKDIR}/desmume-${GITHUB_TAG}/desmume

USE_TOOLS=	gmake

MAKE_FILE=	Makefile.libretro

USE_LANGUAGES=	c c++

.include "../../mk/bsd.fast.prefs.mk"

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-*arm*

.if !empty(MACHINE_ARCH:M*arm*)
CXXFLAGS+=		-marm
BUILD_MAKE_FLAGS+=	DESMUME_JIT=0
BUILD_MAKE_FLAGS+=	DESMUME_JIT_ARM=1
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/desmume_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/desmume_libretro.so

.include "../../mk/bsd.pkg.mk"
