# $NetBSD$

DISTNAME=	libretro-fbalpha2012-neogeo-20170322
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

COMMENT=	Libretro core based on the FB Alpha Neo Geo emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha2012_neogeo
GITHUB_TAG=	d472ad0333e1e68e38bb8ce26db13bd0650dbfb0

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha2012_neogeo_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha2012_neogeo_libretro.so

.include "../../mk/bsd.pkg.mk"
