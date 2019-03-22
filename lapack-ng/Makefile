# $NetBSD$

# This is the first version of updated math/lapack using the upstream
# cmake build system instead of patched Makefiles.
# It is part of the new concept discussed on tech-pkg in the past year,
# with BLAS and LAPACK from either this or OpenBLAS (or others, even external
# MKL), and further cblas and lapacke packages created from the same
# sources as this one, relying on the former.
# This can be considered as replacement of the old math/lapack and
# math/blas once I'm through. I need to figure out good structure
# for math/cblas and math/lapacke first. Maybe even sharing code
# is not needed, as the Makefile is simple enough. Maybe just a decision
# to keep everything from Netlib at the same version.

DISTNAME=	lapack-3.8.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=lapack/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	http://www.netlib.org/lapack/
LICENSE=	modified-bsd

USE_LANGUAGES=		c fortran
USE_TOOLS+=		cmake
USE_CMAKE=		yes

WRKSRC=			${WRKDIR}/${DISTNAME}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=	-DCMAKE_C_COMPILER=gcc
CMAKE_ARGS+=	-DCMAKE_CXX_COMPILER=g++

CMAKE_ARGS=	-DBUILD_DEPRECATED=yes \
		-DBUILD_SHARED_LIBS=ON \
		-DUSE_OPTIMIZED_BLAS=OFF \
		-DUSE_OPTIMIZED_LAPACK=OFF \
		-DCBLAS=OFF -DLAPACKE=OFF

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../mk/bsd.pkg.mk"

