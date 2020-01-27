# $NetBSD: Makefile,v 1.3 2013/03/23 08:37:36 shattered Exp $
#

DISTNAME=	freecell-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.linusakesson.net/files/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	https://www.linusakesson.net/software/freecell.php
COMMENT=	Console version of the solitaire game Freecell
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CURSES_DEFAULT=	ncurses

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
