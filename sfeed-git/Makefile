# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	sfeed-0.9.22
CATEGORIES=	news
MASTER_SITES=	http://codemadness.org/releases/sfeed/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/sfeed/file/README.html
COMMENT=	RSS and Atom parser
LICENSE=	isc

GIT_REPOSITORIES=	sfeed
GIT_REPO.sfeed=		git://git.codemadness.org/sfeed
WRKSRC=			${WRKDIR}/sfeed

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

REPLACE_SH+=		sfeed_opml_export sfeed_update

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
