# $NetBSD$

DISTNAME=	emacs-31.0.50
PKGNAME=	${DISTNAME:S/emacs/emacs31/}
CATEGORIES=	editors
GIT_REPO=	git://git.savannah.gnu.org/emacs.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/emacs/
COMMENT=	GNU editing macros (development version)
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/emacs

AUTOCONF_REQD+=	2.65
TEXINFO_REQD+=	4.13
GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS+=	autoconf automake gm4 gmake gsed gzip makeinfo

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
SPECIAL_PERMS+=		libexec/emacs/${PKGVERSION_NOREV}/${MACHINE_GNU_PLATFORM}/update-game-score ${SETGID_GAMES_PERMS}

.include "options.mk"

# build PATH in the dumped emacs is not a problem
CHECK_WRKREF_SKIP+=	bin/emacs
CHECK_WRKREF_SKIP+=	bin/emacs-${PKGVERSION_NOREV}
CHECK_WRKREF_SKIP+=	libexec/emacs/${PKGVERSION_NOREV}/${MACHINE_GNU_PLATFORM}/emacs.pdmp

CHECK_PORTABILITY_SKIP+=	admin/download-android-deps.sh

PRINT_PLIST_AWK+=	{ gsub(/${PKGVERSION_NOREV}/, "$${PKGVERSION}"); \
			gsub(/${MACHINE_GNU_PLATFORM}/, "$${MACHINE_GNU_PLATFORM}"); \
			print; next; }

post-extract:
	# set auto-load for send-pr library
	cp ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-configure:
	(cd ${WRKSRC}; ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ./autogen.sh)

# by default the filename of the emacs dump contains a fingerprint of the corresponding emacs version
# but this is not needed and makes the PLIST more simple
post-install:
	cd ${DESTDIR}${PREFIX}/libexec/emacs/${PKGVERSION_NOREV}/${MACHINE_GNU_PLATFORM} && \
		mv emacs-*.pdmp emacs.pdmp

.include "../../wip/mk/git-package.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
