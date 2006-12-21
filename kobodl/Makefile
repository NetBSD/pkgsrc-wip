# $NetBSD: Makefile,v 1.1.1.1 2006/12/21 00:02:39 larnor Exp $
#

DISTNAME=	KoboDeluxe-0.4pre10
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/

MAINTAINER=	lars.nordlund@hem.utfors.se
HOMEPAGE=	http://olofson.net/kobodl/
COMMENT=	The classic xkobo game

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
