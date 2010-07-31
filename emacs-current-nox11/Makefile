# $NetBSD: Makefile,v 1.5 2010/07/31 13:30:31 makoto Exp $
#

DISTNAME=	emacs-nox11-24.0.50

PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor, no x11)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo gzip

CONFLICTS=	emacs-[0-9]*

BUILD_TARGET=	bootstrap

GIT_REPOSITORIES=	master
GIT_REPO.master=	git://repo.or.cz/emacs.git
_GIT_FLAGS?=		--depth 1
GIT_MODULE=		emacs
GIT_MODULE.master=	emacs

GNU_CONFIGURE=		yes
INFO_FILES=		yes
REPLACE_PERL=		lib-src/grep-changelog
CHECK_INTERPRETER_SKIP=	bin/grep-changelog

DISTINFO_FILE=	${PKGDIR}/../emacs-current/distinfo
PATCHDIR=	${PKGDIR}/../emacs-current/patches
DESCR_SRC=	${PKGDIR}/../emacs-current/DESCR
#ESSAGE_SRC=	${PKGDIR}/../emacs-current/MESSAGE
PLIST_SRC=	${PKGDIR}/../emacs-current/PLIST

WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--without-x	# nox11
CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

#SUBST_CLASSES+=			test_equal
#SUBST_STAGE.test_equal=		pre-configure
#SUBST_MESSAGE.test_equal=	Fixing bashisms in test(1) usage.
#SUBST_FILES.test_equal=		mac/make-package
#SUBST_SED.test_equal=		-e 's/ == / = /g'

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}

FILESDIR=	${.CURDIR}/../../editors/emacs/files

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

.include "../../wip/mk/git-package.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

