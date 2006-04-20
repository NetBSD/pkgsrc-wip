# $NetBSD: Makefile,v 1.1.1.1 2006/04/20 11:38:12 poppnk Exp $
#

DISTNAME=		rootcheck-0.7
CATEGORIES=		security
MASTER_SITES=		http://www.ossec.net/rootcheck/files/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.ossec.net/rootcheck/
COMMENT=		RootKit detection software

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ossec-rootcheck ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/rootcheck/
	${INSTALL_DATA} ${WRKSRC}/rootcheck.conf ${PREFIX}/share/rootcheck/
	${INSTALL_DATA_DIR} ${PREFIX}/share/rootcheck/db/
	${INSTALL_DATA} ${WRKSRC}/db/*.txt ${PREFIX}/share/rootcheck/db/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rootcheck
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rootcheck/

.include "../../mk/bsd.pkg.mk"
