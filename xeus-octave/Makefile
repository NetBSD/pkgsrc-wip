# $NetBSD$

DISTNAME=	xeus-octave-0.7.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter-xeus/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/jupyter-xeus/xeus-octave/
COMMENT=	Octave kernel for xeus/jupyter
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS=		pkg-config

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LDFLAGS+=	-lexecinfo
.endif

.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/glad/buildlink3.mk"
.include "../../graphics/glfw/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xeus-zmq/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../wip/xcanvas/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
