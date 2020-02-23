# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	tscrape-0.4
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/tscrape/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/tscrape/file/README.html
COMMENT=	Twitter scraper
LICENSE=	isc

GIT_REPOSITORIES=	tscrape
GIT_REPO.tscrape=	git://git.codemadness.org/tscrape
WRKSRC=			${WRKDIR}/tscrape

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
