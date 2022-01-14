# $NetBSD$

DISTNAME=	libzippp-v5.0-1.8.0
PKGNAME=	${DISTNAME:C/-[0-9].*//:S,-v,-,}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=ctabin/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ctabin/libzippp/
COMMENT=	Libzip c++ wrapper
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/libzippp-${DISTNAME}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

CMAKE_USE_GNU_INSTALL_DIRS=	NO

.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
