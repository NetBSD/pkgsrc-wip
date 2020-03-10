# $NetBSD$

DISTNAME=	nudoku-2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jubalh/}
GITHUB_RELEASE=	2.0.0

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://jubalh.github.io/nudoku/
COMMENT=	Ncurses based sudoku game
LICENSE=	gnu-gpl-v3

# Fix gettext includes
SUBST_CLASSES+=		includes
SUBST_STAGE.includes=	post-configure
SUBST_MESSAGE.includes=	Fix gettext includes
SUBST_FILES.includes=	src/main.c
SUBST_FILES.includes+=	src/sudoku.c
SUBST_SED.includes+=	-e 's,"gettext.h",<libintl.h>,'

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

USE_NCURSES=		yes # wmove() doesn't move the cursor in the grid window

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
