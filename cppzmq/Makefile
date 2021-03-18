# $NetBSD$

DISTNAME=	cppzmq-4.7.1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.zeromq.org/
COMMENT=	C++ binding for libzmq
LICENSE=	mit

WRKSRC=		${WRKDIR}/cppzmq-${PKGVERSION}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCPPZMQ_BUILD_TESTS=OFF

.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
