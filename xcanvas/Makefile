# $NetBSD$

DISTNAME=	xcanvas-0.7.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xcanvas/
COMMENT=	2D canvas API for Xeus Kernels
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
