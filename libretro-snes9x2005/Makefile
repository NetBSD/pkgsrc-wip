# $NetBSD$

DISTNAME=	libretro-snes9x2005-20170618
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Snes9x_2005
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	1aecedc999445e9a27e04f665fd562b576775d08

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x2005_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x2005_libretro.so

.include "../../mk/bsd.pkg.mk"
