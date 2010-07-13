# $NetBSD: Makefile,v 1.49 2010/07/13 00:04:00 obache Exp $
#

DISTNAME=	emacs-24.0.50
#PKGNAME=	emacs-24.0.50
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo gzip

CONFLICTS+=	emacs-nox11-[0-9]*

BUILD_TARGET=	bootstrap

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://repo.or.cz/emacs.git
_GIT_FLAGS?=		--depth 1

GNU_CONFIGURE=		yes
INFO_FILES=		yes
REPLACE_PERL=		lib-src/grep-changelog
CHECK_INTERPRETER_SKIP=	bin/grep-changelog

WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
#SPECIAL_PERMS+=		libexec/emacs/${PKGVERSION_NOREV}/${MACHINE_GNU_PLATFORM:Q}/update-game-score ${SETGID_GAMES_PERMS}

.include "options.mk"

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}

FILESDIR=	${.CURDIR}/../../editors/emacs/files

post-extract:
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

.include "../../wip/mk/git-package.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"


#PKG_DEBUG_LEVEL?=       1
#_PKG_SILENT=            # was @ here
