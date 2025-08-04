# $NetBSD: Makefile,v 1.1 2025/02/23 21:54:05 wiz Exp $

DISTNAME=	cpuinfo-0.0.20250724
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=pytorch/}
GITHUB_TAG=	33ed0be77d7767d0e2010e2c3cf972ef36c7c307
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	benchmark-1.6.1.tar.gz
DISTFILES+=	googletest-1.11.0.tar.gz
SITES.benchmark-1.6.1.tar.gz= \
	-${MASTER_SITE_GITHUB:=google/}benchmark/archive/v1.6.1.tar.gz
SITES.googletest-1.11.0.tar.gz= \
	-${MASTER_SITE_GITHUB:=google/}googletest/archive/release-1.11.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pytorch/cpuinfo/
COMMENT=	CPU information library
LICENSE=	2-clause-bsd

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++17
FORCE_CXX_STD=		c++17
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	libcpuinfo.pc.in
CMAKE_CONFIGURE_ARGS+=	-DGOOGLEBENCHMARK_SOURCE_DIR=deps/googlebenchmark
CMAKE_CONFIGURE_ARGS+=	-DGOOGLETEST_SOURCE_DIR=deps/googletest

post-extract:
	${MV} ${WRKDIR}/benchmark-1.6.1 ${WRKSRC}/deps/googlebenchmark
	${MV} ${WRKDIR}/googletest-release-1.11.0 ${WRKSRC}/deps/googletest

.include "../../devel/cmake/build.mk"
#.include "../../benchmarks/google-benchmark/buildlink3.mk"
#.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
