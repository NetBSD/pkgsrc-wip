# $NetBSD: Makefile,v 1.1.1.1 2003/09/05 17:20:38 mjasm Exp $
#

DISTNAME=			am
PKGNAME=			mathomatic-10.5
WRKSRC=				${WRKDIR}/math
CATEGORIES=			wip
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tgz

MAINTAINER=			adam@monkeybyte.org
HOMEPAGE=			http://www.panix.com/~gesslein/
COMMENT=			Small portable symbolic math program

MAKEFILE=			makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/am.1 ${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/am_mathomatic ${PREFIX}/bin/am_mathomatic

.include "../../mk/bsd.pkg.mk"
