# $NetBSD$

DISTNAME=	libretro-prboom-20170410
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
HOMEPAGE=	https://wiki.libretro.com/index.php?title=PrBoom
COMMENT=	Libretro core for Doom
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	e09831c627a84c34d72c3cc892566e1472abb598

USE_TOOLS=	gmake

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/prboom_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/prboom_libretro.so

.include "../../mk/bsd.pkg.mk"
