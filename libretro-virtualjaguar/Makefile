# $NetBSD$

DISTNAME=	libretro-virtualjaguar-20180812
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	virtualjaguar-libretro
GITHUB_TAG=	f3cf607b20ee69e78dbfd80010d3f485fdf67283

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/virtual_jaguar/
COMMENT=	Libretro core based on the Virtual Jaguar Atari Jaguar emulator
LICENSE=	gnu-gpl-v3

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/virtualjaguar_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/virtualjaguar_libretro.so

.include "../../mk/bsd.pkg.mk"
