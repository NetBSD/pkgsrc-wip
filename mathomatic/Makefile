# $NetBSD: Makefile,v 1.7 2004/02/02 14:25:10 bjan2 Exp $
#

DISTNAME=		am-10.7d
PKGNAME=		mathomatic-10.7d
WRKSRC=			${WRKDIR}/math
CATEGORIES=		wip
MASTER_SITES=		http://bjan.freeshell.org/nb/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.panix.com/~gesslein/
COMMENT=		Small portable symbolic math program

MAKEFILE=		makefile

CFLAGS.SunOS+=		-DSOLARIS
CFLAGS+=		-DUNIX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/am_mathomatic ${PREFIX}/bin/am_mathomatic
	${INSTALL_MAN} ${WRKSRC}/am.1 ${PREFIX}/man/man1/am_mathomatic.1

.include "../../mk/bsd.pkg.mk"
