# $NetBSD$

DISTNAME=	libretro-mednafen-ngp-20170321
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_NGP
COMMENT=	Libretro core based on the Mednafen Neo Geo Pocket emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-ngp-libretro
GITHUB_TAG=	af9ff403174f297a18027f3f77910fad2c26d135

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_ngp_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_ngp_libretro.so

.include "../../mk/bsd.pkg.mk"
