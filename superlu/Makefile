# $NetBSD: Makefile,v 1.28 2019/08/11 13:17:49 wiz Exp $

DISTNAME=		superlu-5.2.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=xiaoyeli/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		thomas.orgis@uni-hamburg.de
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		Library for solving large, sparse, nonsymmetric systems of linear equations

USE_CMAKE=		yes
USE_LANGUAGES=		c fortran

CONFIGURE_DIRS=		build
CMAKE_ARG_PATH=		${WRKSRC}

# Armadillo needs shared lib, best would be to install both.
CMAKE_ARGS=		-Denable_blaslib=off \
			-Denable_doc=off \
			-DBUILD_SHARED_LIBS=on

# The cmake machinery finds plain openblas first,
# do not know how to insert a specific lib. But single-threaded
# openblas does make sense, I suppose, for sparse matrices.
BLAS_ACCEPTED=		openblas netlib

TEST_TARGET=		test

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build

.include "../../wip/mk/blas.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
