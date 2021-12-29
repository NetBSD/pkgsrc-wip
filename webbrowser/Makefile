# $NetBSD: Makefile,v 1.1 2013/08/14 01:13:50 outpaddling Exp $

DISTNAME=	webbrowser-0.3.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	84cb894fdd1735a31981494f6ff890e00b3d24a4

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/webbrowser/
COMMENT=	Proxy script for launching "best" available web browser
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
