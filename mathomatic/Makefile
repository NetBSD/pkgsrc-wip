# $NetBSD: Makefile,v 1.10 2004/03/29 18:00:42 minskim Exp $
#

DISTNAME=		am-10.9b
PKGNAME=		mathomatic-10.9b
CATEGORIES=		wip
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.panix.com/~gesslein/
COMMENT=		Small portable symbolic math program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/am
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes
MAKEFILE=		makefile

# gcc's optimizer causes problems with this version of the program
CFLAGS+=		-DUNIX -O0
CFLAGS.SunOS+=		-DSOLARIS

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/am ${PREFIX}/bin/am_mathomatic
	${INSTALL_MAN} ${WRKSRC}/am.1 ${PREFIX}/man/man1/am_mathomatic.1

.include "../../mk/bsd.pkg.mk"
