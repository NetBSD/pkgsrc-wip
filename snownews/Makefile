# $NetBSD: Makefile,v 1.1.1.1 2003/12/23 22:55:59 bjan2 Exp $

DISTNAME=       snownews-1.4.2
CATEGORIES=     www
MASTER_SITES=   http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=     bjan+pkgsrc@bjan.net
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=        Small, curses based RSS feed reader

USE_PKGLOCALEDIR=	YES
USE_BUILDLINK2= 	YES
USE_NCURSES=    	YES
USE_GMAKE=		YES

MAKE_ENV+=	LOCALBASE=${LOCALBASE} PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=	EXTRA_CFLAGS="${CFLAGS}"

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
