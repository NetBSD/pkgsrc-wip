# $NetBSD: Makefile,v 1.8 2012/11/23 22:33:29 othyro Exp $

DISTNAME=	emacs-nox11-24.0.90
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor, no x11)
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake makeinfo gzip autoconf automake
# for example, Mac OS X 10.6.1 has 2.61 which fails
AUTOCONF_REQUIRED=	2.65

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

DISTINFO_FILE=	${PKGDIR}/../emacs-git/distinfo
PATCHDIR=	${PKGDIR}/../emacs-git/patches
DESCR_SRC=	${PKGDIR}/../emacs-git/DESCR
#ESSAGE_SRC=	${PKGDIR}/../emacs-git/MESSAGE
PLIST_SRC=	${PKGDIR}/../emacs-git/PLIST

WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--without-x	# nox11
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

#SUBST_CLASSES+=		test_equal
#SUBST_STAGE.test_equal=	pre-configure
#SUBST_MESSAGE.test_equal=	Fixing bashisms in test(1) usage.
#SUBST_FILES.test_equal=	mac/make-package
#SUBST_SED.test_equal=		-e 's/ == / = /g'

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE}

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}

FILESDIR=	${.CURDIR}/../../editors/emacs/files

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../wip/mk/git-package.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
