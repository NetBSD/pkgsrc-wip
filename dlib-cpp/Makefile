# $NetBSD$

DISTNAME=	dlib-19.24
PKGNAME=	dlib-cpp-19.24
CATEGORIES=	math
MASTER_SITES=	http://dlib.net/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dlib.net/files/
COMMENT=	Machine learning framework written in C++
LICENSE=	boost-license
USE_CMAKE=	yes
USE_LANGUAGES+=	c c++
CMAKE_CONFIGURE_ARGS+=	-B ${WRKSRC}/build
BUILD_DIRS=	build

DOCSDIR=		${PREFIX}/share/doc/dlib
INSTALLATION_DIRS+=	${DOCSDIR}

post-install:
	cd ${WRKSRC}/docs && \
	find . -type d -exec \
		mkdir -p ${DESTDIR}${DOCSDIR}/{} \; && \
	find . -type f -exec \
		${INSTALL_DATA} {} ${DESTDIR}${DOCSDIR}/{} \;

BLAS_C_INTERFACE=	yes

.include "../../mk/blas.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
