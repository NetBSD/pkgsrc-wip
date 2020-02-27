# $NetBSD$

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference code)

LAPACK_COMPONENT=	lapack
LAPACK_COMPONENT_CMAKE_ARGS= \
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF

.include	"../../wip/lapack/Makefile.common"
