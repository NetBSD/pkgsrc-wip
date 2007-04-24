# $NetBSD: Makefile,v 1.2 2007/04/24 20:44:12 christtrekker Exp $
#

DISTNAME=	AlephOne-20070401
CATEGORIES=	games
MASTER_SITES+=	http://umn.dl.sourceforge.net/sourceforge/marathon/
MASTER_SITES+=	http://easynews.dl.sourceforge.net/sourceforge/marathon/
MASTER_SITES+=	http://internap.dl.sourceforge.net/sourceforge/marathon/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@sourceforge.net
HOMEPAGE=	http://marathon.sourceforge.net/
COMMENT=	classic 2.5D FPS game engine, updated to use SDL

#DEPENDS+=	SDL>=1.2.9:../../devel/SDL
#DEPENDS+=	SDL_net>=1.2.5:../../net/SDL_net
#DEPENDS+=	SDL_image>=1.2.4:../../graphics/SDL_image

HAS_CONFIGURE=	yes

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
