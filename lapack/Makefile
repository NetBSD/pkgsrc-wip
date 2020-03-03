# $NetBSD$

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference code)

LAPACK_COMPONENT=	lapack
LAPACK_COMPONENT_CMAKE_ARGS= \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=${BLAS_LIBS:Q} \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF

# This always uses Netlib BLAS. Other optimized BLAS packages bring
# their own LAPACK, hence cblas and lapacke packages use
# mk/blas.buildlink3.mk instead.
.include	"../../wip/blas/buildlink3.mk"

.include	"../../wip/lapack/Makefile.common"
