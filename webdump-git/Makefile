# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	webdump-0.1
CATEGORIES=	textproc
MASTER_SITES=	http://codemadness.org/releases/webdump/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/webdump/file/README.html
COMMENT=	Text-based web client/page dump
LICENSE=	isc

GIT_REPOSITORIES=	webdump
GIT_REPO.webdump=	git://git.codemadness.org/webdump
WRKSRC=			${WRKDIR}/webdump

USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANPREFIX=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_FLAGS+=	CC=${CC:Q}

#REPLACE_SH+=	webdump_opml_export webdump_update

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
