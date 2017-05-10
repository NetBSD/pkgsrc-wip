# $NetBSD$

DISTNAME=	libretro-mame2003-20170306
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the Multiple Arcade Machine Emulator (v0.78)
LICENSE=	no-commercial-use

GITHUB_PROJECT=	mame2003-libretro
GITHUB_TAG=	92ffc48f26f5d47010b5da277de7a89fcc9141ef

EXTRACT_SUFX=	.zip

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

#NOT_FOR_PLATFORM+=	${LP64PLATFORMS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/mame2003_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mame2003_libretro.so

.include "../../mk/bsd.pkg.mk"
