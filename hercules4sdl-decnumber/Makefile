# $NetBSD$

GITHUB_PROJECT=	decNumber
GITHUB_TAG=	da6650957d7dea21b5647c1fa80fa432f2891550 # 5 Jan 2021
DISTNAME=	hercules4sdl-decnumber-2.5
PKGREVISION=	20210105
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of decNumber for Hercules 4.x
LICENSE=	icu-1.8.1-or-later

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/decNumber64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/hercules4sdl

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/hercules4sdl/lib && ${MV} libdecNumber64.a libdecNumber_pic.a

.include "../../mk/bsd.pkg.mk"
