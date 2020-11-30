# $NetBSD$

PKGNAME=	sdl-hercules-crypto-1.0.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/crypto.git
GIT_REVISION=	53dda212770e5981974e11437535a586a22d4aae # Nov 13, 2020
CHECKOUT_DATE=	2020-11-13

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/hyperion
COMMENT=	The SoftDevLabs version of crypto for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

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
