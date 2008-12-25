# $NetBSD: Makefile,v 1.4 2008/12/25 19:26:56 cheusov Exp $
#

DISTNAME=	xsokoban-3.3c
CATEGORIES=	games
MASTER_SITES=	http://www.cs.cornell.edu/andru/release/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.cs.cornell.edu/andru/release/
COMMENT=	Classic logical game

WRKSRC=		${WRKDIR}/xsokoban

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf

PKG_DESTDIR_SUPPORT=	user-destdir

SAVEPATH=		${VARBASE}/games/xsokoban
SCOREFILE=		${SAVEPATH}/scores

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/xsokoban

SPECIAL_PERMS=		bin/xsokoban ${SETGID_GAMES_PERMS}
MAKE_DIRS_PERMS+=	${SAVEPATH} ${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	/dev/null ${SCOREFILE} ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

BUILD_TARGET=		xsokoban

CPPFLAGS+=		-DROOTDIR="\"${PREFIX}/share/xsokoban\""
CPPFLAGS+=		-DSAVEPATH="\"${SAVEPATH}\""
CPPFLAGS+=		-DSCOREPATH="\"${SCOREFILE}\""

AUTO_MKDIRS=		yes

AUTOCONF_REQD=		2.59

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
