# $NetBSD$

DISTNAME=	libzippp-v7.0-1.10.1
PKGNAME=	${DISTNAME:C/-[0-9].*//:S,-v,-,}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=ctabin/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ctabin/libzippp/
COMMENT=	Libzip c++ wrapper
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libzippp-${DISTNAME}
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLIBZIPPP_ENABLE_ENCRYPTION=ON
CMAKE_CONFIGURE_ARGS+=	-DLIBZIPPP_CMAKE_CONFIG_MODE=ON
CMAKE_CONFIGURE_ARGS+=	-DLIBZIPPP_GNUINSTALLDIRS=ON

PKGCONFIG_OVERRIDE=	libzippp.pc.in

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
