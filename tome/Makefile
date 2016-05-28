# $NetBSD: Makefile,v 1.4 2012/10/07 17:17:43 asau Exp $
#

DISTNAME=	tome-300alpha18-src
PKGNAME=	tome-300alpha18
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://t-o-m-e.net/dl/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://t-o-m-e.net/
COMMENT=	Troubles of Middle Earth


BUILD_DIRS=	src
MAKE_FILE=	makefile.std
BUILD_TARGET=	default

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
