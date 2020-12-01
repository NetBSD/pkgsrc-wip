# $NetBSD$

GITHUB_PROJECT=	telnet
GITHUB_TAG=	4b8acebec532057a29bc5662f8ca80d50aeda05c # Nov 13, 2020
DISTNAME=	sdl-hercules-telnet-1.0.0
PKGREVISION=	20201113
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=SDL-Hercules-390/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/telnet
COMMENT=	The SoftDevLabs version of telnet library for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/telnet64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/sdlhercules

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/sdlhercules/lib && ${MV} libtelnet64.a libtelnet_pic.a

.include "../../mk/bsd.pkg.mk"
