# $NetBSD: Makefile,v 1.2 2011/10/07 11:30:17 obache Exp $
#

DISTNAME=	Box2D_v2.2.1
PKGNAME=	${DISTNAME:S/_v/-/}
CATEGORIES=	games
MASTER_SITES=	http://box2d.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.box2d.org/
COMMENT=	Box2D Physics Engine for games

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_DIRS=	Build
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DBOX2D_INSTALL=ON
CMAKE_ARGS+=	-DBOX2D_BUILD_SHARED=ON
CMAKE_ARGS+=	-DBOX2D_BUILD_EXAMPLES=OFF
CMAKE_ARGS+=	-DBOX2D_INSTALL_DOC=ON

.include "../../mk/bsd.pkg.mk"
