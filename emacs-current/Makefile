# $NetBSD: Makefile,v 1.74 2015/04/24 01:19:04 makoto Exp $

.include	"version.mk"
DISTNAME=	emacs-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}
PKGNAME=	emacs25-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (development version)
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf automake gmake gzip makeinfo
# for example, Mac OS X 10.6.1 has 2.61 which fails
AUTOCONF_REQD=	2.65

CONFLICTS+=	emacs-nox11-[0-9]*

MAKE_JOBS_SAFE=	no

GIT_REPOSITORIES=	master
GIT_MODULE.master=	emacs
GIT_REPO.master=	git://git.sv.gnu.org/emacs.git
_GIT_FLAGS?=		--depth 1

GNU_CONFIGURE=		yes
INFO_FILES=		yes
WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}
# For wip special, following gives symbol names when back trace is shown.
CFLAGS+=		-g

BUILD_TARGET=		bootstrap
BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST
PLIST_SUBST+=           DISTNAME=${DISTNAME}

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
#SPECIAL_PERMS+=		libexec/emacs/${PKGVERSION_NOREV}/${MACHINE_GNU_PLATFORM:Q}/update-game-score ${SETGID_GAMES_PERMS}

.include "options.mk"

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}

FILESDIR=	${.CURDIR}/files
# ./configure.lineno: 3555: Syntax error: Bad substitution
# And then add another portablity problem ?
PKGSRC_MAKE_ENV+=       SH=/bin/ksh

post-extract:
	# set auto-load for send-pr library
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-configure:
	(cd ${WRKSRC}; ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ./autogen.sh)

.include "../../wip/mk/git-package.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
