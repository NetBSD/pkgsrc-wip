# $NetBSD$

DISTNAME=	scalapack-2.1.0
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/scalapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.netlib.org/scalapack/
COMMENT=	Scalable Linear Algebra PACKage
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c fortran

CMAKE_ARGS=	-DLAPACK_LIBRARIES=${LAPACK_LIBS:Q} \
		-DBLAS_LIBRARIES=${BLAS_LIBS:Q} \
                -DBUILD_SHARED_LIBS=ON \
                -DBUILD_STATIC_LIBS=ON \

PKGCONFIG_OVERRIDE+=	scalapack.pc.in

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
