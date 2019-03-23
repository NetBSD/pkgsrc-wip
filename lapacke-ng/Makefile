# $NetBSD$

COMMENT=	C interface to a LAPACK library
LAPACK_PART=	lapacke
LAPACK_PART_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES="-lblas" \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES="-llapack" \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../lapack-ng/Makefile.common"
