# $NetBSD$

VERSION=	6.1
DISTNAME=	cgal-${VERSION}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=CGAL/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	https://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++17

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCGAL_INSTALL_MAN_DIR=${PREFIX}/${PKGMANDIR}/man1
#MAKE_CONFIGURE_ARGS+=	-DCGAL_DIR=$CMAKE_INSTALLED_PREFIX/lib/CGAL


REPLACE_SH+=	Scripts/scripts/cgal_create_CMakeLists
REPLACE_SH+=	Scripts/scripts/cgal_create_cmake_script

AUTO_MKDIRS=	yes

# version 5.6.2 had two scripts in bin/, not for sure of necessity
post-install:
	(cd ${WRKSRC}/Scripts/scripts; \
	${INSTALL} cgal_create_CMakeLists ${DESTDIR}${PREFIX}/bin ; \
	${INSTALL} cgal_create_cmake_script ${DESTDIR}${PREFIX}/bin ; \
	)

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
