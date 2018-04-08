# $NetBSD$

DISTNAME=	libretro-craft-20180406
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	Craft
GITHUB_TAG=	03e3ecb8969e58fbeb62722b35dea043bbbbe399

HOMEPAGE=	https://docs.libretro.com/library/craft
COMMENT=	Libretro core based on the 'Craft' Minecraft clone
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.libretro
MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/craft_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/craft_libretro.so

.include "../../mk/bsd.pkg.mk"
