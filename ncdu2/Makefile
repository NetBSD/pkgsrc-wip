# $NetBSD$

DISTNAME=	ncdu-2.2.2
CATEGORIES=	sysutils
MASTER_SITES=	https://dev.yorhel.nl/download/

COMMENT=	Disk usage visualization tool
MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://dev.yorhel.nl/ncdu
LICENSE=	mit

FAKE_NCURSES=	yes
USE_CURSES=	vw_printw

CONFLICTS+=	ncdu-[0-9]*

.include "../../mk/curses.buildlink3.mk"
.include "../../lang/zig/application.mk"
.include "../../mk/bsd.pkg.mk"
