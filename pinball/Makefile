# $NetBSD: Makefile,v 1.11 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	pinball-0.3.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pinball/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://pinball.sourceforge.net/
COMMENT=	Pinball using the Allegro game library
LICENSE=	gnu-gpl-v1


USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake aclocal automake
USE_GAMESGROUP=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
USE_LIBTOOL=		YES
WRKSRC=			${WRKDIR}/${DISTNAME}


MAKE_JOBS_SAFE=	no

BUILD_DEFS+=		VARBASE
SPECIAL_PERMS+=		bin/pinball ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS+=	${VARBASE}/games/pinball ${GAMEDIR_PERMS}
REQD_DIRS_PERMS+=	${VARBASE}/games/pinball/tux ${GAMEDIR_PERMS}
REQD_DIRS_PERMS+=	${VARBASE}/games/pinball/professor ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/pinball/tux/highscores ${GAMEDATA_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/pinball/professor/highscores ${GAMEDATA_PERMS}

post-extract:
	cp ${FILESDIR}/config-rzr.h ${WRKSRC}/base/config-rzr.h

#Allegro is broken in 3.0.1
#.include "../../devel/allegro/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
