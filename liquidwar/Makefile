# $NetBSD: Makefile,v 1.9 2004/04/05 13:30:20 thomasklausner Exp $
#

DISTNAME=	liquidwar-5.6.0
CATEGORIES=	games
#MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

DEPENDS+=	gnome2-dirs>=1.1:../../misc/gnome2-dirs

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
