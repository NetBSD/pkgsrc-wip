# $NetBSD: Makefile,v 1.3 2003/12/24 02:35:22 bjan2 Exp $

DISTNAME=       snownews-1.4.2
CATEGORIES=     www
MASTER_SITES=   http://home.kcore.de/~kiza/software/snownews/download/

MAINTAINER=     bjan+pkgsrc@bjan.net
HOMEPAGE=	http://home.kcore.de/~kiza/software/snownews/
COMMENT=        Small, curses based RSS feed reader

USE_BUILDLINK2= 	YES
USE_GMAKE=		YES
USE_NCURSES=		# missing WA_BOLD, WA_REVERSE, KEY_RESIZE
USE_PKGLOCALEDIR=	YES
BUILD_USES_MSGFMT=	YES

MAKE_ENV+=	LOCALBASE=${LOCALBASE} PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=	EXTRA_CFLAGS="${CFLAGS}" EXTRA_LDFLAGS="${LDFLAGS} -lintl"
MAKE_ENV+=	GMAKE=${GMAKE}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
