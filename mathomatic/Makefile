# $NetBSD: Makefile,v 1.4 2004/01/08 19:14:35 bjan2 Exp $
#

DISTNAME=		am-10.7d
PKGNAME=		mathomatic-10.7d
WRKSRC=			${WRKDIR}/math
CATEGORIES=		wip
MASTER_SITES=		http://bjan.freeshell.org/nb/
EXTRACT_SUFX=		.tgz

MAINTAINER=		bjan+pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.panix.com/~gesslein/
COMMENT=		Small portable symbolic math program

MAKEFILE=		makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/am.1 ${PREFIX}/man/man1/
	${INSTALL_SCRIPT} ${WRKSRC}/am_mathomatic ${PREFIX}/bin/am_mathomatic

.include "../../mk/bsd.pkg.mk"
