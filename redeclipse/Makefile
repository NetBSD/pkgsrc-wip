# $NetBSD$

PKGNAME=	redeclipse-1.6.0
CATEGORIES=	games
GIT_REPO=	https://github.com/red-eclipse/base.git
GIT_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://redeclipse.net/
COMMENT=	A free casual arena shooter

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

BUILD_DIRS=	src
INSTALL_TARGET=	system-install
MAKE_FLAGS+=	MANDIR=/${PKGMANDIR}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
