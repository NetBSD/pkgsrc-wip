# $NetBSD$

GITHUB_PROJECT=	cfiles
DISTNAME=	v1.8
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=mananapr/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/mananapr/cfiles/
COMMENT=	Ncurses file manager written in C with vim like keybindings
LICENSE=	mit

DEPENDS=	fzf-[0-9]*:../../sysutils/fzf

USE_LANGUAGES=	c
USE_TOOLS+=	bash:run

WRKSRC=	${WRKDIR}/cfiles-1.8

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

REPLACE_BASH+=		scripts/clearimg
REPLACE_BASH+=		scripts/clearimg_uberzug
REPLACE_BASH+=		scripts/displayimg
REPLACE_BASH+=		scripts/displayimg_uberzug

SUBST_CLASSES+=		ncurses
SUBST_STAGE.ncurses=	pre-configure
SUBST_MESSAGE.ncurses=	Link with the proper curses type
SUBST_FILES.ncurses=	Makefile
SUBST_SED.ncurses=	-e 's|LIBS += $(NCURSES_LIBS)|LIBS += -l${BUILDLINK_LIBNAME.curses}|g'
SUBST_SED.ncurses+=	-e 's,^CFLAGS,,g'

SUBST_CLASSES+=		gcc
SUBST_STAGE.gcc=	pre-configure
SUBST_FILES.gcc+=	Makefile
SUBST_SED.gcc+=		-e 's|CC = gcc|CC = cc|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cfiles ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cfiles.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${MKDIR} ${DESTDIR}${PREFIX}/share/cfiles/scripts
.for i in clearimg displayimg displayimg_uberzug clearimg_uberzug
	${INSTALL} ${WRKSRC}/scripts/${i} ${DESTDIR}${PREFIX}/share/cfiles/scripts/${i}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
