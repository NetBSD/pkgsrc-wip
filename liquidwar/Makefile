# $NetBSD: Makefile,v 1.1.1.1 2003/04/06 11:33:04 thomasklausner Exp $
#

DISTNAME=	liquidwar-5.5.8
CATEGORIES=	games
MASTER_SITES=	http://freesoftware.fsf.org/download/liquidwar/

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
