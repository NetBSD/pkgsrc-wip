# $NetBSD$

DISTNAME=	libretro-core-info-1.7.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}

GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	https://www.libretro.com/
COMMENT=	Libretro core information

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/libretro/info

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.info ${DESTDIR}${PREFIX}/share/libretro/info

.include "../../mk/bsd.pkg.mk"
