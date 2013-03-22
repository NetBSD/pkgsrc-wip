# $NetBSD: Makefile,v 1.12 2013/03/22 13:57:12 outpaddling Exp $

DISTNAME=	armadillo-3.${DIST_MINOR}.1
PKGNAME=	armadillo-3.${PKG_MINOR}.1
CATEGORIES=	math
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=arma/}

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://sourceforge.net/projects/arma/
COMMENT=	C++ linear algebra library
LICENSE=	mpl-2.0

USE_LANGUAGES+= c c++
USE_CMAKE=	yes

# OS X cannot handle components > 255 in a library version, so strip
# the last digit from Aramdillo's 3-digit minor version.
PKG_MINOR=	80
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
