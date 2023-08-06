# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	TheForceEngine-1.09.410
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=luciusDXL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://theforceengine.github.io/
COMMENT=	Modern "Jedi Engine" replacement supporting Dark Forces
LICENSE=	gnu-gpl-v2

CXXFLAGS+=	-D PROGDATADIR="\"${PREFIX}/share/TheForceEngine\""
USE_LANGUAGES=	c c++14
USE_TOOLS+=	pkg-config

PTHREAD_AUTO_VARS=	yes

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/rtaudio/buildlink3.mk"
.include "../../wip/rtmidi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
