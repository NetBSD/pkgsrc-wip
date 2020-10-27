# $NetBSD$

DISTNAME=	CGAL-5.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=CGAL/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

EXTRACT_SUFX=	.tar.xz

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	https://www.cgal.org/
COMMENT=	Computational Geometry Algorithms Library
LICENSE=	gnu-lgpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++14
CMAKE_ARGS+=	-DCGAL_INSTALL_MAN_DIR=${PREFIX}/${PKGMANDIR}/man1

REPLACE_SH+=	scripts/cgal_create_CMakeLists
REPLACE_SH+=	scripts/cgal_create_cmake_script

# SUBST_CLASSES+=		wrkdir
# SUBST_FILES.wrkdir+=	src/CGAL/CMakeFiles/Export/lib/cmake/CGAL/*.cmake
# SUBST_FILES.wrkdir+=	config/CGALConfig.cmake
# SUBST_MESSAGE.wrkdir=	Removing wrkdir from installed cmake files.
# SUBST_SED.wrkdir=	-e "s|${WRKDIR}/.buildlink|${PREFIX}|g"
# SUBST_STAGE.wrkdir=	pre-install

# pre-install:
#	 find ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
