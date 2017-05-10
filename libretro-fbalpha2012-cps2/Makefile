# $NetBSD$

DISTNAME=	libretro-fbalpha2012-cps2-20170321
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
COMMENT=	Libretro core based on the FB Alpha CPS-2 emulator
LICENSE=	no-commercial-use

GITHUB_PROJECT=	fbalpha2012_cps2
GITHUB_TAG=	7f1755529b79a3fe0c4aec6b79be564ba36dc395

USE_TOOLS=	gmake

USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fbalpha2012_cps2_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fbalpha2012_cps2_libretro.so

.include "../../mk/bsd.pkg.mk"
