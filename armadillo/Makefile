# $NetBSD: Makefile,v 1.13 2014/10/02 15:31:38 uccwen Exp $

DISTNAME=	armadillo-4.${DIST_MINOR}.2
PKGNAME=	armadillo-4.${PKG_MINOR}.2
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
LICENSE=	mpl-2.0

USE_LANGUAGES+= c c++
USE_CMAKE=	yes

# OS X cannot handle components > 255 in a library version, so strip
# the last digit from Aramdillo's 3-digit minor version.
PKG_MINOR=	45
DIST_MINOR=	${PKG_MINOR}0

CMAKE_ARGS+=	-DINSTALL_LIB_DIR=${PREFIX}/lib

SUBST_CLASSES=		minor
SUBST_STAGE.minor=	post-patch
SUBST_FILES.minor=	CMakeLists.txt
SUBST_SED.minor=	-e "s|ARMA_MINOR ${DIST_MINOR}|ARMA_MINOR ${PKG_MINOR}|g"

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
