# $NetBSD$

DISTNAME=	dspdfviewer-1.15.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=dannyedel/}

MAINTAINER=	santhosh.raju@gmail.com
HOMEPAGE=	http://dspdfviewer.danny-edel.de/
COMMENT=	Dual-Screen PDF Viewer for latex-beamer
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	v${VERSION}

WRKSRC=		${WRKDIR}/${DISTNAME}
CONFIGURE_DIRS=	build
BUILD_DIRS=	build

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config
USE_CMAKE=	yes
CMAKE_ARGS+=	-DBuildTests=OFF
CMAKE_ARG_PATH=	${WRKSRC}/build
BUILD_MAKE_FLAGS+= VERBOSE=1

DEPENDS+=	qt5-qttools>=5.5.1:../../x11/qt5-qttools

BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs>=1.63
BUILDLINK_API_DEPENDS.poppler-qt5+=	poppler-qt5>=0.50.0

pre-configure:
	mkdir -p ${WRKSRC}/build

do-configure:
	cd ${WRKSRC}/build && cmake .. ${CMAKE_ARGS}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
