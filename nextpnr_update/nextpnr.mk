# $NetBSD: nextpnr.mk,v 1.6 2024/10/14 06:45:39 wiz Exp $

NEXTPNR_VERSION=0.0.20250829
DISTNAME=	nextpnr-${NEXTPNR_VERSION}
.if defined(HIMBAECHEL_UARCH)
PKGNAME=	nextpnr-${NEXTPNR_TARGET}-${HIMBAECHEL_UARCH}-${NEXTPNR_VERSION}
.else
PKGNAME=    nextpnr-${NEXTPNR_TARGET}-${NEXTPNR_VERSION}
.endif
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=YosysHQ/}
GITHUB_PROJECT=	nextpnr
GITHUB_TAG=	bc086c012f509dab61a44eabb8cac47a48ebc60f
WRKSRC=		${WRKDIR}/nextpnr-${GITHUB_TAG}

MAINTAINER?=	thorpej@NetBSD.org
HOMEPAGE=	https://github.com/YosysHQ/nextpnr
COMMENT?=	A portable FPGA place and route tool
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
