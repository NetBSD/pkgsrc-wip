# $NetBSD$

DISTNAME=	dlib-19.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://dlib.net/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dlib.net/files/
COMMENT=	Machine learning framework written in C++ (python bindings)
LICENSE=	boost-license
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
CMAKE_CONFIGURE_ARGS+=	-B ${WRKSRC}/build
BUILD_DIRS=	build

DEPENDS+=	dlib-cpp>=19.24:../../wip/dlib-cpp

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../wip/dlib-cpp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
