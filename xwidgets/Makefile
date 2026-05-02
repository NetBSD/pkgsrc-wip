# $NetBSD$

DISTNAME=	xwidgets-0.30.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xwidgets/
COMMENT=	C++ backend for jupyter interactive widgets
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xproperty/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
