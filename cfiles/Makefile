# $NetBSD$

GITHUB_PROJECT=	cfiles
DISTNAME=	v1.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mananapr/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/mananapr/cfiles/
COMMENT=	Ncurses file manager written in C with vim like keybindings
LICENSE=	mit

DEPENDS=	fzf-[0-9]*:../../sysutils/fzf

USE_LANGUAGES=	c

WRKSRC=	${WRKDIR}/cfiles-1.3

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		gcc
SUBST_STAGE.gcc=	pre-configure
SUBST_FILES.gcc+=	Makefile
SUBST_SED.gcc+=		-e 's|CC = gcc|CC = cc|g'

SUBST_CLASSES+=		ncurses
SUBST_STAGE.ncurses=	pre-configure
SUBST_MESSAGE.ncurses=	Link with the proper curses type
SUBST_FILES.ncurses=	Makefile
SUBST_SED.ncurses=	-e 's|LIBS =  -lncursesw|LIBS = -l${BUILDLINK_LIBNAME.curses}|g'

SUBST_CLASSES+=		install
SUBST_STAGE.install=	pre-configure
SUBST_FILES.install=	Makefile
SUBST_SED.install+=	-e 's|DEST = /usr/local|DEST = ${DESTDIR}${PREFIX}|g'
SUBST_SED.install+=	-e 's|cp -v|${INSTALL_PROGRAM}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfiles ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cfiles.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
