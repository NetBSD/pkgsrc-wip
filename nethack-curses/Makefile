# $NetBSD$
#

# builtin curses: crashes at the end with
# #0  redrawwin (win=0x0) at /usr/src/lib/libcurses/touchwin.c:149
# Also it doesn't adjust to resizing the terminal window as advertised.
# ncurses:
#USE_BUILTIN.curses=	no
#CURSES_DEFAULT=	ncurses
# crashes at startup.

.include "../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-curses-${NETHACK_VERSION}

COMMENT=		The curses based version of NetHack

DEPENDS+=		nethack-lib-${NETHACK_VERSION}{,nb*}:../../games/nethack-lib

BUILD_TARGET=		nethack
MAKE_ENV+=		GAME=nethack
MAKE_ENV+=		GTYPE=-curses

INSTALLATION_DIRS+=	bin
do-install:
	${RUN}${INSTALL_PROGRAM} ${WRKSRC}/src/nethack ${DESTDIR}${PREFIX}/bin/nethack-curses

DISTINFO_FILE?=		${.CURDIR}/../../games/nethack-lib/distinfo
PATCHDIR=		${.CURDIR}/../../games/nethack-lib/patches

SPECIAL_PERMS+=		${PREFIX}/bin/nethack-curses			\
			    ${GAMEPERM}

.include "../../mk/bsd.pkg.mk"
