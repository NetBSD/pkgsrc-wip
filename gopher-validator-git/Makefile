# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	gopher-validator-0.1
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/gopher-validator/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/gopher-validator
COMMENT=	Gopher validator and happy helper
LICENSE=	isc

GIT_REPOSITORIES=		gopher-validator
GIT_REPO.gopher-validator=	git://bitreich.org/gopher-validator
WRKSRC=				${WRKDIR}/gopher-validator

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_MAN} ${WRKSRC}/gopher-validator.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/gopher-validator ${DESTDIR}${PREFIX}/bin

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
