# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	vatomic-2.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-s4c/}

MAINTAINER=	db7@sdf.org
HOMEPAGE=	https://github.com/open-s4c/vatomic/
COMMENT=	Formally verified atomic operations
LICENSE=	mit

USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS=	-DVATOMIC_DEV=off

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
