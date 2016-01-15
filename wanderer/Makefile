# $NetBSD$

DISTNAME=	wanderer-dev.3.2.1
PKGREVISION=    1
CATEGORIES=	games
MASTER_SITES=	http://e271.net/~marina/
EXTRACT_SUFX=	.tgz

MAINTAINER=	catskillmarina@gmail.com
HOMEPAGE=	http://e271.net/~marina/wanderer.html
COMMENT=	Wanderer is a game similar to Boulderdash, Repton, XOR and others
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=     man man/man6 bin share/wanderer share/wanderer/screens games

SUBST_CLASSES+= wanderer
SUBST_STAGE.wanderer= pre-build
SUBST_FILES.wanderer= wand_head.h
SUBST_SED.wanderer= -e "s,/usr/local/share/wanderer/screens,${PREFIX}/share/wanderer/screens,"
SUBST_SED.wanderer+= -e "s,/var/games/wandererscores,${PREFIX}/games/wandererscores,"
SUBST_SED.wanderer+= -e "s,\#include <ncurses.h>,\#include <curses.h>,"

SUBST_CLASSES+= wand-mk
SUBST_STAGE.wand-mk= pre-build
SUBST_FILES.wand-mk= Makefile
SUBST_SED.wand-mk= -e 's|${DESTDIR}||'
SUBST_SED.wand-mk+= -e "s,/usr/local/,${PREFIX}/,"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wanderer
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/games
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wanderer/screens
	${INSTALL_DATA} -m 0644 ${WRKSRC}/screens/* ${DESTDIR}${PREFIX}/share/wanderer/screens/
	${INSTALL} -o ${GAMES_USER} -g ${GAMES_GROUP} -m 2755 ${WRKSRC}/wanderer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wanderer.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../mk/bsd.pkg.mk"
.include "../../mk/curses.buildlink3.mk"
