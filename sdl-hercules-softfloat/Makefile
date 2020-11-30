# $NetBSD$

PKGNAME=	sdl-hercules-softfloat-3.5.0
CATEGORIES=	emulators
GIT_REPO=	https://github.com/SDL-Hercules-390/SoftFloat.git
GIT_REVISION=	1991ebd466f46590d02aa68729f3283fe430bec0 # Nov 13, 2020
CHECKOUT_DATE=	2020-11-13

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/SDL-Hercules-390/SoftFloat
COMMENT=	The SoftDevLabs version of SoftFloat for Hercules 4.x
LICENSE=	modified-bsd

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c

USE_CMAKE=	yes
BLDDIR=		${WRKDIR}/SoftFloat64.Release
CONFIGURE_DIRS=	${BLDDIR}
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_ARGS+=	-D INSTALL_PREFIX=${PREFIX}/lib/sdlhercules

pre-configure:
	${MKDIR} ${BLDDIR}

post-install:
	cd ${DESTDIR}${PREFIX}/lib/sdlhercules/lib && ${MV} libSoftFloat64.a libSoftFloat_pic.a

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
