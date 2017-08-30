# $NetBSD$

DISTNAME=	libretro-beetle-wswan-20170621
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_WSWAN
COMMENT=	Libretro core based on the Mednafen Wonderswan emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-wswan-libretro
GITHUB_TAG=	59f31b2c54037c2177ffbde40118f8d8f33c674b

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
