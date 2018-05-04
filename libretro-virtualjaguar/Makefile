# $NetBSD$

DISTNAME=	libretro-virtualjaguar-20180502
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	virtualjaguar-libretro
GITHUB_TAG=	2ce1ec0a5f3e8d357795a3b5cfeffc8d91cdd52a

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
