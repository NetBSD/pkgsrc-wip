# $NetBSD$

DISTNAME=	wanderer-dev
PKGREVISION=    1
CATEGORIES=	games
MASTER_SITES=	http://e271.net/~marina/
EXTRACT_SUFX=	.tgz

MAINTAINER=	catskillmarina@gmail.com
HOMEPAGE=	http://e271.net/~marina/wanderer.html
COMMENT=	Wanderer is a game similar to Boulderdash, Repton, XOR and others
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=     man man/man6 bin share/wanderer share/wanderer/screens games

do-build:
	${MV} ${WRKSRC}/wand_head.h ${WRKSRC}/wand_head.h.pre
	${SED} -e "s,/usr/local/share/wanderer/screens,${PREFIX}/share/wanderer/screens," \
               -e "s,/var/games/wandererscores,${PREFIX}/games/wandererscores," \
		${WRKSRC}/wand_head.h.pre > ${WRKSRC}/wand_head.h
	${MV} ${WRKSRC}/wand_head.h ${WRKSRC}/wand_head.h.pre
	${SED} -e "s,#include <ncurses.h>,#include <curses.h>," \
		${WRKSRC}/wand_head.h.pre > ${WRKSRC}/wand_head.h
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre
	${SED} -e 's|${DESTDIR}||' ${WRKSRC}/Makefile.pre  \
            > ${WRKSRC}/Makefile
	${SED} -i -e "s,/usr/local/,${PREFIX}/," ${WRKSRC}/Makefile
	cd ${WRKSRC}; make

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wanderer
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/games
	echo ${DESTDIR}${PREFIX}/games
	echo ${DESTDIR}${PREFIX}/games
	echo ${DESTDIR}${PREFIX}/games
	echo ${DESTDIR}${PREFIX}/games
	echo ${DESTDIR}${PREFIX}/games
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/wanderer/screens
	${INSTALL_DATA} -m 0644 ${WRKSRC}/screens/* ${DESTDIR}${PREFIX}/share/wanderer/screens/
        ${INSTALL} -o ${GAMES_USER} -g ${GAMES_GROUP} -m 2755 ${WRKSRC}/wanderer ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wanderer.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/

.include "../../mk/bsd.pkg.mk"
.include "../../mk/curses.buildlink3.mk"
