# $NetBSD: Makefile,v 1.1 2021/04/20 20:37:03 thor Exp $

COMMENT=		C interface to a BLAS library
PKGREVISION=		1
LAPACK_COMPONENT=	cblas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DCBLAS=ON -DLAPACKE=OFF -DLAPACK=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../math/blas/buildlink3.mk"
.include "../../wip/lapack64/Makefile.common"
.include "../../mk/bsd.pkg.mk"
