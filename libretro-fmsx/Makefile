# $NetBSD$

DISTNAME=	libretro-fmsx-20170223
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=FMSX
COMMENT=	Libretro core for emulation of the MSX family of home computers
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fmsx-libretro
GITHUB_TAG=	a58af0d162fd80852903ec87cd271b3220fdca22

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fmsx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fmsx_libretro.so

.include "../../mk/bsd.pkg.mk"
