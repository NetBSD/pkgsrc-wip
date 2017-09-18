# $NetBSD: Makefile,v 1.74 2015/04/24 01:19:04 makoto Exp $

.include	"version.mk"
DISTNAME=	emacs-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}
PKGNAME=	emacs27-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/emacs/
COMMENT=	GNU editing macros (development version)
LICENSE=	gnu-gpl-v3

GIT_REPOSITORIES=	master
GIT_MODULE.master=	emacs
GIT_REPO.master=	git://git.sv.gnu.org/emacs.git
_GIT_FLAGS?=		--depth 1

WRKSRC=		${WRKDIR}/emacs

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	autoconf automake gm4 gmake gsed gzip makeinfo
# for example, Mac OS X 10.6.1 has 2.61 which fails
AUTOCONF_REQD=	2.65
# NetBSD has 4.8
TEXINFO_REQD=	4.13

CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMES_USER}
# For wip special, following gives symbol names when back trace is shown.
CFLAGS+=		-g

USE_GAMESGROUP=		yes

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE
PLIST_SRC+=		PLIST

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

.include "options.mk"

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}

PRINT_PLIST_AWK+=       { gsub(/${PKGVERSION_NOREV}/, "$${PKGVERSION}"); \
			gsub(/${MACHINE_GNU_PLATFORM}/, "$${MACHINE_GNU_PLATFORM}"); \
			print; next; }

post-extract:
	# set auto-load for send-pr library
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-configure:
	(cd ${WRKSRC}; ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ./autogen.sh)

.include "../../wip/mk/git-package.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
