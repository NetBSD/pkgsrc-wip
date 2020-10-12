# $NetBSD$

DISTNAME=	hpl-2.3
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.netlib.org/benchmark/hpl/

MAINTAINER=	jhigh@NetBSD.org
HOMEPAGE=	https://www.netlib.org/benchmark/hpl/
COMMENT=	Portable Implementation of the High-Performance Linpack Benchmark for Distributed-Memory Computers
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../mk/blas.buildlink3.mk"
.include "../../parallel/openmpi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
