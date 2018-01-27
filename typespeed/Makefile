# $NetBSD: Makefile,v 1.18 2012/10/07 17:17:53 asau Exp $
#

DISTNAME=		typespeed-0.6.4
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://tobias.eyedacor.org/typespeed/

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		http://tobias.eyedacor.org/typespeed/
COMMENT=		Game to measure your typing speed, with network mode


USE_LANGUAGES=		c
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
BUILD_DEFS+=		GAMEOWN GAMEGRP GAMEDATAMODE

EGDIR=			${PREFIX}/share/examples/typespeed
SCORE_PATH=		${PREFIX}/var/games
CONF_FILES_PERMS+=	${EGDIR}/typespeedrc ${PREFIX}/etc/typespeedrc \
			${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/typespeed.score ${GAMEOWN} \
			games 664

SUBST_CLASSES+=			man-paths
SUBST_STAGE.man-paths=		pre-patch
SUBST_FILES.man-paths=		man/typespeed.6
SUBST_SED.man-paths=		-e 's|/etc/|${PREFIX}/etc/|g'
SUBST_MESSAGE.man-paths=	Adjusting path in the game's man page

post-install:
	cd ${WRKSRC}/etc && ${BUILD_MAKE_CMD}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/typespeedrc ${EGDIR}
	${CHOWN} ${GAMEOWN}:games ${SCORE_PATH}/typespeed.score
	${CHMOD} 664 ${SCORE_PATH}/typespeed.score

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
