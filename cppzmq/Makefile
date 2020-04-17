# $NetBSD$

DISTNAME=	cppzmq-4.6.0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.zeromq.org/
COMMENT=	C++ binding for libzmq
LICENSE=	mit

WRKSRC=		${WRKDIR}/cppzmq-4.6.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
