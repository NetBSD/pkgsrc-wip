# $NetBSD: Makefile,v 1.28 2007/04/11 06:51:52 rillig Exp $
#

DISTNAME=	emacs-22.0.97
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

USE_TOOLS+=	gmake makeinfo gzip

CONFLICTS+=	emacs-nox11-[0-9]*

BUILD_TARGET=	bootstrap

CVS_REPOSITORIES=	emacs
CVS_ROOT.emacs=		${CVS_ROOT_GNU}/emacs

GNU_CONFIGURE=		yes
INFO_FILES=		yes
REPLACE_PERL=		lib-src/grep-changelog

WRKSRC=		${WRKDIR}/emacs

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		GAMEOWN=${GAMEOWN:Q}

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		GAMEDATAMODE

PLIST_SRC+=		PLIST

SUBST_CLASSES+=			test_equal
SUBST_STAGE.test_equal=		pre-configure
SUBST_MESSAGE.test_equal=	Fixing bashisms in test(1) usage.
SUBST_FILES.test_equal=		mac/make-package
SUBST_SED.test_equal=		-e 's/ == / = /g'

MAKE_DIRS_PERMS+=	${VARBASE}/games/emacs ${GAMEOWN:Q} ${GAMEGRP} ${GAMEDIRMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/snake-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/games/emacs/tetris-scores ${GAMEOWN:Q} ${GAMEGRP:Q} ${GAMEDATAMODE:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs_current
PKG_OPTIONS_OPTIONAL_GROUPS+= toolkit
PKG_OPTIONS_GROUP.toolkit= motif gtk xaw carbon
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcarbon)
.  if !exists(/System/Library/Frameworks/Carbon.framework)
PKG_FAIL_REASON=	"This platform dosen't support Carbon"
.  else
APPLICATIONS_DIR=	Applications

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--with-carbon
CONFIGURE_ARGS+=	--enable-carbon-app=${PREFIX}/${APPLICATIONS_DIR}

PLIST_SRC+=		PLIST.carbon
PLIST_SUBST+=		APPLIDATIONS_DIR=${APPLICATIONS_DIR:Q}

INSTALLATION_DIRS=	${APPLICATIONS_DIR}

CHECK_WRKREF_SKIP+=	${APPLICATIONS_DIR}/Emacs.app/Contents/MacOS/Emacs

post-install:
	for d in `find ${PREFIX}/${APPLICATIONS_DIR}/Emacs.app -type d ! -name CVS -print`; do  \
		rm -rf $${d}/CVS; \
		rm -rf $${d}/.cvsignore; \
	done

.  endif
.elif !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mxaw)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--without-carbon

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.  if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.  elif !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.  elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.  endif
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-carbon
.endif

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION}

FILESDIR=	${.CURDIR}/../../editors/emacs/files

post-extract:
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

.include "../../mk/oss.buildlink3.mk"
.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
