# $NetBSD$

DISTNAME=	libretro-yabause-20171107
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/yabause/
COMMENT=	Libretro core based on the Yabause Sega Saturn emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	yabause
GITHUB_TAG=	c55eef9796f1612bab60824685e66ee58657e576

USE_TOOLS=	gmake

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
BUILD_DIRS=	libretro

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro/yabause_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/yabause_libretro.so

.include "../../mk/bsd.pkg.mk"
