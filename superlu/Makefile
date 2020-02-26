# $NetBSD: Makefile,v 1.28 2019/08/11 13:17:49 wiz Exp $

PORTVERSION=		5.2.1
DISTNAME=		superlu-${PORTVERSION}
PKGNAME=		superlu-${PORTVERSION}
PKGREVISION=		8
CATEGORIES=		math
MASTER_SITES=		-https://github.com/xiaoyeli/superlu/archive/v${PORTVERSION}.tar.gz

MAINTAINER=		thomas.orgis@uni-hamburg.de
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		ANSI C routine library for the solution of sparse linear systems

USE_LANGUAGES=		c fortran
USE_CMAKE=		yes

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

# /usr/bin/ar: ../libsuperlu.a: Error reading dlamch.o: File truncated
#MAKE_JOBS_SAFE=		no

TEST_TARGET=		test

post-extract:
	${RUN} mkdir -p ${WRKSRC}/build

.include "../../wip/mk/blas.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
