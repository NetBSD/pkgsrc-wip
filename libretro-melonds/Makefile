# $NetBSD$

DISTNAME=	libretro-melonds-20171207
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	melonDS
GITHUB_TAG=	72959ea6074035eaaf4ab3736dfad502f1ff5bb5

HOMEPAGE=	https://docs.libretro.com/library/melonds/
COMMENT=	Libretro core based on the melonDS emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/melonds_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/melonds_libretro.so

.include "../../mk/bsd.pkg.mk"
