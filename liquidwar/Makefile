# $NetBSD: Makefile,v 1.8 2004/01/25 02:23:56 grantbeattie Exp $
#

DISTNAME=	liquidwar-5.6.0
CATEGORIES=	games
#MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

DEPENDS+=	gnome2-dirs>=1.1:../../misc/gnome2-dirs

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-debug

.include "../../wip/allegro/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
