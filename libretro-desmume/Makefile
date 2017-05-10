# $NetBSD$

DISTNAME=	libretro-desmume-20170211
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the Desmume Nintendo DS emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	desmume
GITHUB_TAG=	63ed05bbf02fa841adbdfd158cdc96033b48ddc0

WRKSRC=		${WRKDIR}/desmume-${GITHUB_TAG}/desmume

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/desmume_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/desmume_libretro.so

.include "../../mk/bsd.pkg.mk"
