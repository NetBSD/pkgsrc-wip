# $NetBSD: Makefile,v 1.2 2004/07/18 15:25:58 ppostma Exp $
#

DISTNAME=		n0t-1.87
CATEGORIES=		net
MASTER_SITES=		http://r3b00t.itsec.pl/n0t/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://r3b00t.itsec.pl/n0t/
COMMENT=		Network OS Tracer

WRKSRC=		${WRKDIR}/n0t
USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/n0t ${PREFIX}/sbin/n0t
	${INSTALL_MAN} ${WRKSRC}/n0t.1 ${PREFIX}/share/man/man1/n0t.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/n0t/
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/n0t/

.include "../../mk/bsd.pkg.mk"
