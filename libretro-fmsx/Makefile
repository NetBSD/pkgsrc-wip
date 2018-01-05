# $NetBSD$

DISTNAME=	libretro-fmsx-20170703
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/fmsx/
COMMENT=	Libretro core for emulation of the MSX family of home computers
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fmsx-libretro
GITHUB_TAG=	7c0c7333a02ebe885c2f469a4dac362faaf23189

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fmsx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fmsx_libretro.so

.include "../../mk/bsd.pkg.mk"
