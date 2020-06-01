# $NetBSD: Makefile,v 1.2 2018/09/08 14:10:52 leot Exp $

DISTNAME=	grabtitle-0.1
CATEGORIES=	www
MASTER_SITES=	http://codemadness.org/releases/grabtitle/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://codemadness.org/git/grabtitle/file/README.html
COMMENT=	HTML title grabber
LICENSE=	isc

GIT_REPOSITORIES=	grabtitle
GIT_REPO.grabtitle=	git://git.codemadness.org/grabtitle
WRKSRC=			${WRKDIR}/grabtitle

BUILD_TARGET=	build

USE_LANGUAGES=	c99

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grabtitle ${DESTDIR}${PREFIX}/bin

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
