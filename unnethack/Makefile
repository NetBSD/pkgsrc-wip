# $NetBSD: Makefile,v 1.1.1.1 2011/06/07 20:14:13 rhialto Exp $
#

DISTNAME=	unnethack-3.5.3-20101010
#PKGREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unnethack/}

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://unnethack.sourceforge.net/
COMMENT=	Variant and further development of NetHack
LICENSE=	nethack-license

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=--enable-wizmode=rhialto
CONFIGURE_ARGS+=--enable-curses-graphics
CONFIGURE_ARGS+=--enable-tty-graphics
#CONFIGURE_ARGS+=--enable-x11-graphics	# unrecognized
CONFIGURE_ENV+=CHOWN=true
CONFIGURE_ENV+=CHGRP=true

# For data files
BUILD_TARGET=	datastuff
INSTALL_TARGET=	manpages install-dat
INSTALLATION_DIRS=	${PKGMANDIR}/man6 ${GAMEDIR}

# For executable
BUILD_TARGET+=	unnethack
INSTALL_TARGET+=binfiles

USE_LANGUAGES=	c
USE_NCURSES=	yes
USE_TOOLS+=	lex yacc make awk
# ^^ use flex instead of lex if there is an error from make;
# for me, on supposedly almost identically configured systems, it only
# works if I put flex here instead of lex and I have not found out why.

USE_GAMESGROUP=		yes
NETHACK_USER=		${GAMES_USER}
NETHACK_GROUP=		${GAMES_GROUP}
BUILD_DEFS+=		GAMES_USER GAMES_GROUP
GAMEPERM=		${NETHACK_USER} ${NETHACK_GROUP} 2555

GAMEDIR=		${PREFIX}/share/${NETHACK_DIR}
NETHACK_DIR=		unnethackdir350
VARDIR=			/var/games/unnethack350
MAKE_ENV+=		GAMEDIR=${GAMEDIR:Q}
MAKE_ENV+=		VARDIR=${VARDIR:Q}
MAKE_ENV+=		CURSESLIBDIR=${BUILDLINK_PREFIX.ncurses:Q}/lib

# For X:
#BUILD_TARGET+=	x11tiles 	# tiles seem to be broken
#BUILD_TARGET+=	rip.xpm
#FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/misc
#INSTALLATION_DIRS+=	lib/X11/app-defaults lib/X11/fonts/misc


# Special handling for the scorefiles: we do not want to delete
# them between package installations and deinstallations.
#
# These should eventually migrate to a better location, but keep them
# here for now until we lose backward compatibility because of changes
# to the fileformat.
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/logfile \
			${NETHACK_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/perm \
			${NETHACK_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/record \
			${NETHACK_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/xlogfile \
			${NETHACK_USER} ${NETHACK_GROUP} 664

REQD_DIRS_PERMS+=	${VARDIR}					\
			${NETHACK_USER} ${NETHACK_GROUP} 775
REQD_DIRS_PERMS+=	${VARDIR}/save					\
			${NETHACK_USER} ${NETHACK_GROUP} 770

CHECK_FILES_SKIP+=	${VARDIR}/logfile				\
			${VARDIR}/perm					\
			${VARDIR}/record				\
			${VARDIR}/xlogfile
# For binary:
SPECIAL_PERMS+=		${GAMEDIR}/unnethack				\
			    ${GAMEPERM}
# For X:
#post-install:
#	${INSTALL_DATA} ${WRKSRC}/dat/x11tiles \
#	    ${DESTDIR}${GAMEDIR}
#	${INSTALL_DATA} ${WRKSRC}/win/X11/NetHack.ad \
#	    ${DESTDIR}${PREFIX}/lib/X11/app-defaults/UnNetHack
#	${INSTALL_DATA} ${WRKSRC}/win/X11/nh10.bdf \
#	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
#	${INSTALL_DATA} ${WRKSRC}/win/X11/ibm.bdf \
#	    ${DESTDIR}${PREFIX}/lib/X11/fonts/misc
#	${INSTALL_DATA} ${WRKSRC}/win/X11/nethack.rc \
#	    ${DESTDIR}${GAMEDIR}/unnethack.x11.rc


.include "../../devel/ncurses/buildlink3.mk"	# >= 5.0
#.include "../../x11/libXaw/buildlink3.mk"	# for X
#.include "../../x11/libXpm/buildlink3.mk"	# for X
#.include "../../x11/libXt/buildlink3.mk"	# for X
.include "../../mk/bsd.pkg.mk"
