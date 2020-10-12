# $NetBSD: Makefile,v 1.13 2014/10/02 15:31:38 uccwen Exp $

DISTNAME=	armadillo-9.${DIST_MINOR}.3
PKGNAME=	armadillo-9.${PKG_MINOR}.3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arma/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
LICENSE=	mpl-2.0

USE_TOOLS+=	cmake
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes

# OS X cannot handle components > 255 in a library version, so strip
# the last digit from Aramdillo's 3-digit minor version.
PKG_MINOR=	40
DIST_MINOR=	${PKG_MINOR}0

CMAKE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib
CONFIGURE_ENV+=	LAPACK_LIBS=${LAPACK_LIBS:Q} BLAS_LIBS=${BLAS_LIBS:Q}

SUBST_CLASSES=		minor
SUBST_STAGE.minor=	post-patch
SUBST_FILES.minor=	CMakeLists.txt
SUBST_SED.minor=	-e "s|ARMA_MINOR ${DIST_MINOR}|ARMA_MINOR ${PKG_MINOR}|g"

.include "../../mk/blas.buildlink3.mk"
.include "../../wip/superlu/buildlink3.mk"
.include "../../math/arpack-ng/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
