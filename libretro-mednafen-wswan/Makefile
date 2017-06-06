# $NetBSD$

DISTNAME=	libretro-mednafen-wswan-20170321
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_WSWAN
COMMENT=	Libretro core based on the Mednafen Wonderswan emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-wswan-libretro
GITHUB_TAG=	a5e6485791df67de92fa070b6612b260a0d05ec2

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_wswan_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_wswan_libretro.so

.include "../../mk/bsd.pkg.mk"
