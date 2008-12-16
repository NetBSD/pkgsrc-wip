# $NetBSD: Makefile,v 1.1.1.1 2008/12/16 17:10:49 cheusov Exp $
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

CHANGABLEPATH=		${VARBASE}/xsokoban
SAVEPATH=		${CHANGABLEPATH}/saves
SCOREPATH=		${CHANGABLEPATH}/scores

CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11:Q}/include/X11
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11:Q}/lib
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/xsokoban

SPECIAL_PERMS=		bin/xsokoban ${SETGID_GAMES_PERMS}
REQD_DIRS_PERMS+=	${SAVEPATH}  ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
REQD_DIRS_PERMS+=	${SCOREPATH} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

MAKE_FLAGS+=		INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_FLAGS+=		INSTALL_MAN=${INSTALL_MAN:Q}

BUILD_TARGET=		xsokoban

CPPFLAGS+=		-DROOTDIR="\"${PREFIX}/share/xsokoban\""
CPPFLAGS+=		-DSAVEPATH="\"${SAVEPATH}\""
CPPFLAGS+=		-DSCOREPATH="\"${SCOREPATH}\""
CPPFLAGS+=		-DOWNSER="\"GAMES_USER\""

AUTO_MKDIRS=		yes

AUTOCONF_REQD=		2.59

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
