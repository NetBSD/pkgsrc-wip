# $NetBSD: Makefile,v 1.12 2025/10/23 20:39:51 wiz Exp $

DISTNAME=	chrono-date-3.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=HowardHinnant/}
GITHUB_PROJECT=	date
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://howardhinnant.github.io/date/date.html
COMMENT=	Date and time library based on the C++11/14/17 <chrono> header
LICENSE=	mit

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TZ_LIB=ON

.include "../../devel/cmake/build.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
