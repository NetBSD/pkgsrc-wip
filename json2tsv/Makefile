# $NetBSD: Makefile,v 1.9 2019/08/01 18:55:29 leot Exp $

DISTNAME=	json2tsv-0.1
CATEGORIES=	textproc
MASTER_SITES=	http://codemadness.org/releases/json2tsv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codemadness.org/git/json2tsv/file/README.html
COMMENT=	Convert JSON to TSV
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=		CC=${CC:Q}

.include "../../mk/bsd.pkg.mk"
