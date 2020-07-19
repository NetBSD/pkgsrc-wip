# $NetBSD$

.include "../../wip/lapack/Makefile.common"

COMMENT=	Basic Linear Algebra System (Netlib reference implementation)

LAPACK_COMPONENT=	blas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../mk/bsd.pkg.mk"
