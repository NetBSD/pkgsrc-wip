# $NetBSD: Makefile,v 1.10 2004/04/15 11:03:05 jmmv Exp $
#

DISTNAME=	liquidwar-5.6.0
CATEGORIES=	games
#MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

USE_BUILDLINK3=	YES
USE_DIRS+=	gnome2-1.5
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
