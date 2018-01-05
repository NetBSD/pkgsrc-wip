# $NetBSD$

DISTNAME=	libretro-snes9x2005-20170826
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2005/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	12b1ae1a13434dd0bdc5305d36811643306d8e3e

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2005_libretro.so

.include "../../mk/bsd.pkg.mk"
