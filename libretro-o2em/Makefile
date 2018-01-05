# $NetBSD$

DISTNAME=	libretro-o2em-20170124
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://docs.libretro.com/library/o2em/
COMMENT=	Libretro core for Magnavox Odyssey 2 and VideoPac emulation
LICENSE=	artistic

GITHUB_TAG=	1d62d4ed86e6c1a7d65dff49e4368edb30690665

USE_TOOLS=	gmake

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/o2em_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/o2em_libretro.so

.include "../../mk/bsd.pkg.mk"
