# $NetBSD: Makefile,v 1.1 2013/08/14 01:13:50 outpaddling Exp $
#

DISTNAME=	webbrowser-0.3.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/webbrowser/releases/new
COMMENT=	Proxy script for launching "best" available web browser
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=	yes

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${MKDIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
