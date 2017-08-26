# $NetBSD$

DISTNAME=	libretro-core-info-20170813
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro core information

GITHUB_TAG=	73d9546f2db8c8c45132c1903a6d5ac55ce56cba

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/libretro/info

.include "../../mk/bsd.pkg.mk"
