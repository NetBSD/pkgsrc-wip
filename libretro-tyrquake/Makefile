# $NetBSD$

DISTNAME=	libretro-tyrquake-20180425
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	tyrquake
GITHUB_TAG=	5aa8c55d64320260ca06ae87b5f1eadf8d297912

HOMEPAGE=	https://docs.libretro.com/library/tyrquake/
COMMENT=	Libretro core for the TyrQuake interpreter for Quake and Quakeworld
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/tyrquake_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/tyrquake_libretro.so

.include "../../mk/bsd.pkg.mk"
