# $NetBSD$

GITHUB_PROJECT=	glm
DISTNAME=	0.9.9.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=g-truc/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://glm.g-truc.net/
COMMENT=	C++ mathematics library for software based on the OpenGL GLSL
LICENSE=	mit

WRKSRC=		${WRKDIR}/glm-0.9.9.3
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	cmake/glm.pc.in

.include "../../mk/bsd.pkg.mk"
