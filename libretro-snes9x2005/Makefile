# $NetBSD$

DISTNAME=	libretro-snes9x2005-20170817
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Snes9x_2005
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	b94a8041a928f5018d753d21d62507c1511af8d4

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2005_libretro.so

.include "../../mk/bsd.pkg.mk"
