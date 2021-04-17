# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	sfeed_curses-0.9.10
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/sfeed_curses/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/sfeed_curses/file/README.html
COMMENT=	sfeed curses UI
LICENSE=	isc

GIT_REPOSITORIES=	sfeed_curses
GIT_REPO.sfeed_curses=	git://git.codemadness.org/sfeed_curses
WRKSRC=			${WRKDIR}/sfeed_curses

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

REPLACE_SH+=		sfeed_markread

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
