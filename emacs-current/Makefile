# $NetBSD: Makefile,v 1.59 2012/03/26 07:03:31 makoto Exp $
#

.include	"version.mk"
DISTNAME=	emacs-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}
#PKGNAME=	emacs-24.0.50
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	editors
MASTER_SITES=	#

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo gzip autoconf automake
# for example, Mac OS X 10.6.1 has 2.61 which fails
AUTOCONF_REQUIRED=	2.65

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

# Check some related libraries for inclusion.
MESALIB_VERSION!=	\
	(${PKG_INFO} -e MesaLib || ${ECHO} "0") | \
	${SED} -e 's/MesaLib-//' 

GL_VERSION!=	\
	(${PKG_INFO} -e gl || ${ECHO} "0") | \
	${SED} -e 's/gl-//' 

post-extract:
	# set auto-load for send-pr library
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp
# Comment out for debug.
#.if ${MESALIB_VERSION:R} >= 7.8
#	@echo '  ** MesaLib version 7.8.2 or later installed.'
#.endif

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../wip/mk/git-package.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.if ${MESALIB_VERSION:R} >= 7.8 || ${GL_VERSION:R} >= 7.8
.include "../../wip/gl/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../wip/MesaLib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
