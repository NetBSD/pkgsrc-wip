# $NetBSD$

PKGNAME=	sdl-hercules-telnet-1.0.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/telnet.git
GIT_REVISION=	4b8acebec532057a29bc5662f8ca80d50aeda05c # Nov 13, 2020
CHECKOUT_DATE=	2020-11-13

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

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
