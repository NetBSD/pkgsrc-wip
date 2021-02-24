# $NetBSD$

GITHUB_PROJECT= rlottie
GITHUB_TAG=     v0.2
DISTNAME=       v0.2
PKGNAME=        ${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	    graphics
MASTER_SITES=   ${MASTER_SITE_GITHUB:=Samsung/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=       https://github.com/Samsung/rlottie/
COMMENT=        A platform independent standalone library that plays Lottie Animation.  
LICENSE=        mit

WRKSRC=        ${WRKDIR}/rlottie-0.2
USE_CMAKE=     yes
USE_LANGUAGES= c c++


CMAKE_ARGS=    -DCMAKE_INSTALL_PREFIX=${PREFIX}
CMAKE_ARGS=    -DLIB_INSTALL_DIR=${PREFIX}/lib

PKGCONFIG_OVERRIDE+=    rlottie.pc.in

.include "../../mk/bsd.pkg.mk"
