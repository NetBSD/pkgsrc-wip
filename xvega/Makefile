# $NetBSD$

DISTNAME=	xvega-0.1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xvega/
COMMENT=	C++ api for Vega-Lite
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../wip/xproperty/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
