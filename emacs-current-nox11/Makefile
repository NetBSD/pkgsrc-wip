# $NetBSD: Makefile,v 1.1.1.1 2007/02/20 09:32:49 uebayasi Exp $
#

DISTNAME=	emacs-22.0.93
PKGNAME=	emacs-nox11-22.0.93
CATEGORIES=	editors
MASTER_SITES=	#
CONFLICTS=	emacs-[0-9]*

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

USE_TOOLS+=	gmake makeinfo pkg-config gzip

BUILD_TARGET=	bootstrap

CVS_REPOSITORIES=	emacs
CVS_ROOT.emacs=		${CVS_ROOT_GNU}/emacs
CVS_MODULE.emacs=	emacs

GNU_CONFIGURE=		yes
INFO_FILES=		yes

DISTINFO_FILE=	${PKGDIR}/../emacs-current/distinfo
PATCHDIR=	${PKGDIR}/../emacs-current/patches
DESCR_SRC=	${PKGDIR}/../emacs-current/DESCR
MESSAGE_SRC=	${PKGDIR}/../emacs-current/MESSAGE
PLIST_SRC=	${PKGDIR}/../emacs-current/PLIST
WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--without-x	# nox11
CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

SUBST_CLASSES+=			test_equal
SUBST_STAGE.test_equal=		pre-configure
SUBST_MESSAGE.test_equal=	Fixing bashisms in test(1) usage.
SUBST_FILES.test_equal=		mac/make-package
SUBST_SED.test_equal=		-e 's/ == / = /g'

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION}

FILESDIR=	${.CURDIR}/../../editors/emacs/files

PLIST_SUBST+=	EMACS_PKGNAME=${PKGNAME:C/-nox11//:Q}

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

.include "../../mk/oss.buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
