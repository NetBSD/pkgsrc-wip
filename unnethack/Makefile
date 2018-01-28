# $NetBSD: Makefile,v 1.7 2014/04/20 14:53:47 rhialto Exp $
#

DISTNAME=	unnethack-5.1.0-20131208
#PKGREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unnethack/}
VER=		510

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://sourceforge.net/apps/trac/unnethack/
COMMENT=	Variant and further development of NetHack
LICENSE=	nethack-license

GNU_CONFIGURE=	YES
MAKE_JOBS_SAFE=	no

CONFIGURE_ARGS+=	--enable-wizmode=rhialto
CONFIGURE_ARGS+=	--enable-curses-graphics
CONFIGURE_ARGS+=	--enable-tty-graphics
# Don't do the user/permission setting during build time.
CONFIGURE_ENV+=		CHOWN=true
CONFIGURE_ENV+=		CHGRP=true

# For executable
BUILD_TARGET=	unnethack
INSTALL_TARGET=	binfiles

# For data files.
# (BUG: building the datafiles first causes a double compile
# of the game executable somehow)
BUILD_TARGET+=		datastuff
INSTALL_TARGET+=	manpages install-dat
INSTALLATION_DIRS=	${PKGMANDIR}/man6 ${GAMEDIR}

PLIST_SUBST+=	VER=$(VER)
PLIST_VARS=	x11

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
NETHACK_DIR=		unnethackdir$(VER)
VARDIR=			/var/games/unnethack$(VER)
MAN6DIR=		${PREFIX}/${PKGMANDIR}/man6
#MAKE_ENV+=		GAMEDIR=${GAMEDIR:Q}
MAKE_ENV+=		MANDIR=${MAN6DIR:Q}
#MAKE_ENV+=		VARDIR=${VARDIR:Q}
MAKE_ENV+=		CURSESLIBDIR=${BUILDLINK_PREFIX.ncurses}/lib
CONFIGURE_ARGS+=	--with-gamesdir=${VARDIR:Q}
CONFIGURE_ARGS+=	--with-sharedir=${GAMEDIR:Q}
CONFIGURE_ARGS+=	--with-unsharedir=${GAMEDIR:Q}



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
REQD_DIRS_PERMS+=	${VARDIR}/bones					\
			${NETHACK_USER} ${NETHACK_GROUP} 770
REQD_DIRS_PERMS+=	${VARDIR}/level					\
			${NETHACK_USER} ${NETHACK_GROUP} 770
REQD_DIRS_PERMS+=	${VARDIR}/saves					\
			${NETHACK_USER} ${NETHACK_GROUP} 770

CHECK_FILES_SKIP+=	${VARDIR}/logfile				\
			${VARDIR}/perm					\
			${VARDIR}/record				\
			${VARDIR}/xlogfile
# For binary:
SPECIAL_PERMS+=		${GAMEDIR}/unnethack				\
			    ${GAMEPERM}

# The distribution tarball has all files unreadable for "others".
# When installing such a file this will remain so.
# So fix it.
post-extract:
	${CHMOD} -R go+r ${WRKSRC}

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"	# >= 5.0
.include "../../mk/bsd.pkg.mk"
