# $NetBSD: Makefile,v 1.9 2019/08/01 18:55:29 leot Exp $

DISTNAME=	json2tsv-0.5
CATEGORIES=	textproc
MASTER_SITES=	http://codemadness.org/releases/json2tsv/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/json2tsv/file/README.html
COMMENT=	Convert JSON to TSV
LICENSE=	isc

GIT_REPOSITORIES=	json2tsv
GIT_REPO.json2tsv=	git://git.codemadness.org/json2tsv
WRKSRC=			${WRKDIR}/json2tsv

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
