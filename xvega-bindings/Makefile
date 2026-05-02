# $NetBSD$

DISTNAME=	xvega-bindings-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xvega-bindings/
COMMENT=	Bindings from xvega -> xeus
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/xvega/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
