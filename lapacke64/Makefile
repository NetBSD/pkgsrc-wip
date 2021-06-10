# $NetBSD: Makefile,v 1.1 2021/04/20 20:40:47 thor Exp $

COMMENT=		C interface to a LAPACK library
LAPACK_COMPONENT=	lapacke64
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=-llapack64 \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../../wip/lapack64/buildlink3.mk"
.include "../../wip/lapack64/Makefile.common"

.include "../../mk/bsd.pkg.mk"
