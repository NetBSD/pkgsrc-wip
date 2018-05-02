# $NetBSD$

DISTNAME=	libretro-virtualjaguar-20180425
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	virtualjaguar-libretro
GITHUB_TAG=	0418a44f35c9bea4fa8145e66b10073547b5a9be

HOMEPAGE=	https://docs.libretro.com/library/virtual_jaguar/
COMMENT=	Libretro core for Atari Jaguar emulation
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/virtualjaguar_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/virtualjaguar_libretro.so

.include "../../mk/bsd.pkg.mk"
