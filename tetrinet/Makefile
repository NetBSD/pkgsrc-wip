# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 06:01:01 xtraeme Exp $

DISTNAME=	tetrinet
PKGNAME=	tetrinet-0.7a
CATEGORIES=	games
MASTER_SITES=	http://achurch.org/tetrinet/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Console tetrinet client

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tetrinet-server ${PREFIX}/bin
	@${INSTALL_DATA_DIR} ${PREFIX}/share/tetrinet/doc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/tetrinet/doc
	${INSTALL_DATA} ${WRKSRC}/tetrinet.txt ${PREFIX}/share/tetrinet/doc

.include "../../mk/bsd.pkg.mk"
