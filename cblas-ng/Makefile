# $NetBSD$

LAPACK_PART=	cblas
LAPACK_PART_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES="-lblas" \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES="-llapack" \
	-DCBLAS=ON -DLAPACKE=OFF

# To-be Makefile.common
PORTVERSION=    3.8.0
DISTNAME=	lapack-${PORTVERSION}
PKGNAME=        ${LAPACK_PART}-ng-${PORTVERSION}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=lapack/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.netlib.org/lapack/
LICENSE=	modified-bsd

USE_LANGUAGES=		c fortran
USE_TOOLS+=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/${DISTNAME}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS=	-DBUILD_DEPRECATED=yes \
		-DBUILD_SHARED_LIBS=ON \
		${LAPACK_PART_CMAKE_ARGS}

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"

