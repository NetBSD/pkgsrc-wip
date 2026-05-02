# $NetBSD$

DISTNAME=	xproperty-0.12.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xproperty/
COMMENT=	C++ properties and observer pattern
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
