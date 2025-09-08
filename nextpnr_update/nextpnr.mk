# $NetBSD:$

NEXTPNR_VERSION=0.9
DISTNAME=	nextpnr-${NEXTPNR_VERSION}
.if defined(HIMBAECHEL_UARCH)
PKGNAME=	nextpnr-${NEXTPNR_TARGET}-${HIMBAECHEL_UARCH}-${NEXTPNR_VERSION}
.else
PKGNAME=    nextpnr-${NEXTPNR_TARGET}-${NEXTPNR_VERSION}
.endif
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_PROJECT=	nextpnr
GITHUB_TAG=		${DISTNAME}

MAINTAINER?=thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT?=	Portable FPGA place and route tool
LICENSE=	isc

DISTINFO_FILE?=	${.CURDIR}/../../devel/nextpnr/distinfo
PATCHDIR?=	${.CURDIR}/../../devel/nextpnr/patches

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCURRENT_GIT_VERSION=${NEXTPNR_VERSION}
CMAKE_CONFIGURE_ARGS+=	-DARCH=${NEXTPNR_TARGET}
.if defined(NEXTPNR_TARGET_ARGS)
CMAKE_CONFIGURE_ARGS+=	${NEXTPNR_TARGET_ARGS}
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
