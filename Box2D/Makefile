# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	Box2D_v2.2.1
PKGNAME=	${DISTNAME:S/_v/-/}
CATEGORIES=	games
MASTER_SITES=	http://box2d.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.box2d.org/
COMMENT=	Box2D Physics Engine for games

CONFIGURE_DIRS=	Build
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBOX2D_INSTALL=ON
CMAKE_ARGS+=	-DBOX2D_BUILD_SHARED=ON
CMAKE_ARGS+=	-DBOX2D_BUILD_EXAMPLES=OFF
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC=ON

.include "../../mk/bsd.pkg.mk"
