# $NetBSD$

DISTNAME=	libretro-core-info-20170907
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro core information

GITHUB_TAG=	1a34edf18946b83ab9c27a1a734ba7fb62cb7375

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/libretro/info

.include "../../mk/bsd.pkg.mk"
