# $NetBSD: Makefile,v 1.1.1.1 2003/05/22 08:05:43 jeremy-c-reed Exp $

DISTNAME=	defendguin-0.0.10
CATEGORIES=	games
MASTER_SITES=	http://www.nbswebfx.com/downloads/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/defendguin/
COMMENT=	'Clone of "Defender" arcade game'

USE_X11=	YES
USE_BUILDLINK2=	YES

USE_GMAKE=	YES
MAKE_ENV+=	PREFIX=${LOCALBASE}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
