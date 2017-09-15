# $NetBSD$

DISTNAME=	libretro-core-info-20170914
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro core information

GITHUB_TAG=	fb05fe13d318f183b990f386af132d06835d3973

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/libretro/info

.include "../../mk/bsd.pkg.mk"
