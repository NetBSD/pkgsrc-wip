# $NetBSD$

DISTNAME=	xeus-lua-0.10.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-lua/
COMMENT=	Jupyter kernel for Lua, based on the xeus framework
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../lang/lua54/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../wip/xcanvas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
