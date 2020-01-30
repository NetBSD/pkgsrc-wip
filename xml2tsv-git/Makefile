# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	xml2tsv-0.1
CATEGORIES=	textproc
MASTER_SITES=	http://git.katolaz.net/xml2tsv/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://git.katolaz.net/xml2tsv/
COMMENT=	Simple xml-to-tsv converter, based on xmlparser
LICENSE=	isc

GIT_REPOSITORIES=	xml2tsv
GIT_REPO.xml2tsv=	git://git.katolaz.net/xml2tsv/
WRKSRC=			${WRKDIR}/xml2tsv

USE_LANGUAGES=	c99

MAKE_FLAGS+=		PREFIX=${PREFIX:Q}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		CC=${CC:Q}

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/xml2tsv.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
