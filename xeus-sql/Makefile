# $NetBSD$

DISTNAME=	xeus-sql-0.4.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.com
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-sql/
COMMENT=	Jupyter Kernel for SQL Databases
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
# MAKE_ENV+=		VERBOSE=1


.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../databases/soci/buildlink3.mk"
.include "../../wip/tabulate/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xcanvas/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../wip/xvega-bindings/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
