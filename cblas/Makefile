# $NetBSD$

COMMENT=		C interface to a BLAS library
LAPACK_COMPONENT=	cblas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=${BLAS_LIBS:Q} \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=${LAPACK_LIBS:Q} \
	-DCBLAS=ON -DLAPACKE=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../wip/mk/blas.buildlink3.mk"
.include "../../wip/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
