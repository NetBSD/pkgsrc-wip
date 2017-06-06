# $NetBSD$

DISTNAME=	libretro-fbalpha2012-cps1-20170321
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

COMMENT=	Libretro core based on the FB Alpha CPS-1 emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha2012_cps1
GITHUB_TAG=	9992f07f020cd7bf54ef80953ba756aa519d039d

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha2012_cps1_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha2012_cps1_libretro.so

.include "../../mk/bsd.pkg.mk"
