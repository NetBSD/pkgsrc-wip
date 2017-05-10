# $NetBSD$

DISTNAME=	libretro-yabause-20170124
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the Yabause Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	yabause
GITHUB_TAG=	c8f4c5732c0ebb02c8f3aae757c6575a25d41896

USE_TOOLS=	gmake

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}/libretro

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/yabause_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/yabause_libretro.so

.include "../../mk/bsd.pkg.mk"
