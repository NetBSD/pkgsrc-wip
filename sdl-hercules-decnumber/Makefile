# $NetBSD$

GITHUB_PROJECT=	decNumber
GITHUB_TAG=	e41bb5245dbfdde1dd3d55b2c755230325b2e4be # Nov 13, 2020
DISTNAME=	sdl-hercules-decnumber-3.68.0
PKGREVISION=	20201113
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of decNumber for Hercules 4.x
LICENSE=	qpl-v1.0

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/decNumber64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/sdlhercules

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/sdlhercules/lib && ${MV} libdecNumber64.a libdecNumber_pic.a

.include "../../mk/bsd.pkg.mk"
