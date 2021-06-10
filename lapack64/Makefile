# $NetBSD: Makefile,v 1.43 2021/05/12 14:32:51 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference implementation)

LAPACK_COMPONENT=	lapack64
LAPACK_COMPONENT_CMAKE_ARGS= \
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=ON

.include "../../wip/blas64/buildlink3.mk"

.include "../../wip/lapack64/Makefile.common"
.include "../../mk/bsd.pkg.mk"
