# $NetBSD: Makefile,v 1.2 2003/07/02 08:45:01 blef Exp $
#

DISTNAME=	liquidwar-5.5.9
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	unique multiplayer wargame

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--enable-debug

post-install:
	${RM} ${PREFIX}/bin/liquidwar
	${RM} ${PREFIX}/bin/liquidwar-server
	${MV} ${PREFIX}/games/liquidwar ${PREFIX}/bin
	${MV} ${PREFIX}/games/liquidwar-server ${PREFIX}/bin
	-${RMDIR} ${PREFIX}/games

.include "../../wip/allegro/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
