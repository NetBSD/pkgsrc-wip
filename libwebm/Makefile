# $NetBSD$

DISTNAME=	libwebm-1.0.0.32
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=webmproject/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webmproject.org/
COMMENT=	High-quality, open and free video format for the web
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libwebm-${DISTNAME}
USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
