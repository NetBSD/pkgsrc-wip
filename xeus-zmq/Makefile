# $NetBSD$

DISTNAME=	xeus-zmq-4.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fasmtail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-zmq/
COMMENT=	ZeroMQ-based middleware for xeus
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../net/cppzmq/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
