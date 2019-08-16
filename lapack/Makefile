# $NetBSD$

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference code)

LAPACK_PART=	lapack
LAPACK_PART_CMAKE_ARGS= \
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF

.include	"../../wip/lapack/Makefile.common"
