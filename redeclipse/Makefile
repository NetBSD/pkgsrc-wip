# $NetBSD$

PKGNAME=	redeclipse-${VERSION}
DISTNAME=	red-eclipse-v${VERSION}
CATEGORIES=	games
VERSION=	1.5.3
MASTER_SITES=	https://s3-us-west-2.amazonaws.com/red-eclipse/

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	http://redeclipse.net/
COMMENT=	A free casual arena shooter

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

BUILD_DIRS=	src
INSTALL_TARGET=	system-install
MAKE_FLAGS+=	MANDIR=/${PKGMANDIR}

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
