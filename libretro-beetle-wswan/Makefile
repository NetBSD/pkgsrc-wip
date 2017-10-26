# $NetBSD$

DISTNAME=	libretro-beetle-wswan-20171024
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://wiki.libretro.com/index.php?title=Beetle/Mednafen_WSWAN
COMMENT=	Libretro core based on the Mednafen Wonderswan emulator
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	beetle-wswan-libretro
GITHUB_TAG=	ff4bbff7597b772bb5aec38dfada0b915840fb39

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
