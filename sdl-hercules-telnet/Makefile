# $NetBSD$

PKGNAME=	sdl-hercules-telnet-1.0.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/telnet.git
GIT_REVISION=	650fad2ce96f76bf6d62cd3f8e70ae7e5f214fd3 # Nov 29, 2019
CHECKOUT_DATE=	2019-11-29

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/telnet
COMMENT=	The SoftDevLabs version of telnet library for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c c++

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
