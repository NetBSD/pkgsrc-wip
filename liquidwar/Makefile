# $NetBSD: Makefile,v 1.6 2003/08/29 15:42:37 thomasklausner Exp $
#

DISTNAME=	liquidwar-5.5.9
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-debug

.include "../../wip/allegro/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
