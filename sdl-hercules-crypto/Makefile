# $NetBSD$

PKGNAME=	sdl-hercules-crypto-1.0.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/crypto.git
GIT_REVISION=	02174c9e2fc7dfeeaf88fbe57172baaf07c650bb # Nov 29, 2019
CHECKOUT_DATE=	2019-11-29

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of crypto for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c c++

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/crypto64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/sdlhercules

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/sdlhercules/lib && ${MV} libcrypto64.a libcrypto_pic.a

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
