# $NetBSD: Makefile,v 1.1.1.1 2004/06/11 12:15:17 ppostma Exp $

DISTNAME=	qstat25c
PKGNAME=	qstat-2.5c
CATEGORIES=	games
MASTER_SITES=	http://www.qstat.org/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.qstat.org/
COMMENT=	Program that gathers real-time statistics from game servers

NO_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_PROGRAM} ${WRKSRC}/qstat ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qstatdoc.html ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/template/* ${PREFIX}/share/doc/${PKGBASE}/template
	${INSTALL_DATA} ${WRKSRC}/contrib.cfg ${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/qstat.cfg ${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
