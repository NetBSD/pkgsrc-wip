# $NetBSD$

DISTNAME=	highway-0.12.2
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	highway

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/highway/
COMMENT=	C++ library for SIMD
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DHWY_SYSTEM_GTEST:BOOL=TRUE

PKGCONFIG_OVERRIDE+=	libhwy-contrib.pc.in
PKGCONFIG_OVERRIDE+=	libhwy-test.pc.in
PKGCONFIG_OVERRIDE+=	libhwy.pc.in

BUILDLINK_API_DEPENDS.googletest+=	googletest>=1.10.0nb1
.include "../../devel/googletest/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
