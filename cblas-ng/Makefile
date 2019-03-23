# $NetBSD$

COMMENT=	C interface to a BLAS library
LAPACK_PART=	cblas
LAPACK_PART_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES="-lblas" \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES="-llapack" \
	-DCBLAS=ON -DLAPACKE=OFF

.include "../lapack-ng/Makefile.common"
