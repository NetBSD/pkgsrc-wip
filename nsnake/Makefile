# $NetBSD$

DISTNAME=	nsnake-3.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnake/GNU-Linux/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	http://nsnake.sourceforge.net/
COMMENT=	Classic snake game on the terminal
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

FAKE_NCURSES=	yes

MAKE_FLAGS+=	DESTDIR=${DESTDIR} MANDIR=${PREFIX}/${PKGMANDIR}/man6 PREFIX=${PREFIX}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
