# $NetBSD$

PKGNAME=	sdl-hercules-decnumber-3.68.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/decNumber.git
GIT_REVISION=	963bd1fa94ff52adfe4c9ebc8cd874a641db7679 # Nov 29, 2019
CHECKOUT_DATE=	2019-11-29

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of decNumber for Hercules 4.x
LICENSE=	qpl-v1.0

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c c++

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/decNumber64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/sdlhercules

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/sdlhercules/lib && ${MV} libdecNumber64.a libdecNumber_pic.a

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
