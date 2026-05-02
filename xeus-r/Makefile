# $NetBSD$

DISTNAME=	xeus-r-0.10.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-r/
COMMENT=	R Kernel for jupyter
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-evaluate-[0-9]*:../../devel/R-evaluate
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-hera-[0-9]*:../../wip/R-hera
DEPENDS+=	R-IRdisplay-[0-9]*:../../devel/R-IRdisplay
DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-repr-[0-9]*:../../devel/R-repr
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../math/R/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xcanvas/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../wip/xvega-bindings/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
