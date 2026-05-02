# $NetBSD$

DISTNAME=	xeus-sqlite-0.10.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-sqlite/
COMMENT=	Jupyter kernel for sqlite databases
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/SQLiteCpp/buildlink3.mk"
.include "../../wip/tabulate/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xcanvas/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../wip/xvega-bindings/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
