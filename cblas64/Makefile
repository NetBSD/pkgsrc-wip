# $NetBSD: Makefile,v 1.1 2021/04/20 20:37:03 thor Exp $

COMMENT=		C interface to a BLAS library
LAPACK_COMPONENT=	cblas64
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DCBLAS=ON -DLAPACKE=OFF -DLAPACK=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../wip/blas64/buildlink3.mk"
.include "../../wip/lapack64/Makefile.common"
.include "../../mk/bsd.pkg.mk"
