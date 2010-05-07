# $NetBSD: Makefile,v 1.1.1.1 2010/05/07 16:59:32 emil_s Exp $
#

DISTNAME=	freecell-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.linusakesson.net/files/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://www.linusakesson.net/software/freecell.php
COMMENT=	Console version of the solitaire game Freecell

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
