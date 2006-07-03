# $NetBSD: Makefile,v 1.7 2006/07/03 13:21:48 ghen Exp $
#

DISTNAME=		supertux-0.1.3
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://download.berlios.de/supertux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://supertux.berlios.de/
COMMENT=		2D jump'n run game in the style of the Super Mario ones

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++

BUILDLINK_API_DEPENDS.SDL= 	SDL>=1.2.9nb1
BUILDLINK_API_DEPENDS.SDL_mixer=	SDL_mixer>=1.2.6nb3
BUILDLINK_API_DEPENDS.SDL_image=	SDL_image>=1.2.4nb2

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
