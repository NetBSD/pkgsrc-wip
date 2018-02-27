# $NetBSD$

DISTNAME=	libretro-snes9x2005-20180221
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	ea4775801b424594e309a3413815b67cc53d6ac1

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2005/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

USE_TOOLS=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2005_libretro.so

.include "../../mk/bsd.pkg.mk"
