# $NetBSD$

DISTNAME=	wanderer-dev.3.2.1
PKGREVISION=    1
PKGNAME=	wanderer-dev.3.2.1
DIST_SUBDIR=	${PKGVERSION_NOREV}
CATEGORIES=	games
MASTER_SITES=	http://e271.net/~marina/
EXTRACT_SUFX=	.tgz

MAINTAINER=	catskillmarina@gmail.com
HOMEPAGE=	http://e271.net/~marina/wanderer.html
COMMENT=	Wanderer is a game similar to Boulderdash, Repton, XOR and others
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+= wanderer
SUBST_STAGE.wanderer= pre-build
SUBST_FILES.wanderer= wand_head.h
SUBST_SED.wanderer= -e "s,/usr/local/share/wanderer/screens,${PREFIX}/share/wanderer/screens,"
SUBST_SED.wanderer+= -e "s,\#include <ncurses.h>,\#include <curses.h>,"

SUBST_CLASSES+= wand-mk
SUBST_STAGE.wand-mk= pre-build
SUBST_FILES.wand-mk= Makefile
SUBST_SED.wand-mk= -e 's|${DESTDIR}||'
SUBST_SED.wand-mk+= -e "s,/usr/local/,${PREFIX}/,"

SETGIDGAME=	yes
SPECIAL_PERMS=	bin/wanderer ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS+=     man man/man6 bin share/wanderer share/wanderer/screens games

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wanderer ${DESTDIR}${PREFIX}/bin/wanderer
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wanderer/screens
	${INSTALL_DATA} ${WRKSRC}/screens/* ${DESTDIR}${PREFIX}/share/wanderer/screens/
	${INSTALL_MAN} ${WRKSRC}/wanderer.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
