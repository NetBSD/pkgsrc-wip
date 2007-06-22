# $NetBSD: Makefile,v 1.5 2007/06/22 18:36:46 christtrekker Exp $
#

DISTNAME=	AlephOne-20070401
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=marathon/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@sourceforge.net
HOMEPAGE=	http://marathon.sourceforge.net/
COMMENT=	Classic 2.5D FPS game engine, updated to use SDL

#DEPENDS+=	SDL>=1.2.9:../../devel/SDL
#DEPENDS+=	SDL_net>=1.2.5:../../net/SDL_net
#DEPENDS+=	SDL_image>=1.2.4:../../graphics/SDL_image

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c++
USE_LANGUAGES+=	c

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
