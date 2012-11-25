# $NetBSD: Makefile,v 1.3 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=		rootcheck-0.7
CATEGORIES=		security
MASTER_SITES=		http://www.ossec.net/rootcheck/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ossec.net/rootcheck/
COMMENT=		RootKit detection software

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ossec-rootcheck ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/rootcheck/
	${INSTALL_DATA} ${WRKSRC}/rootcheck.conf ${DESTDIR}${PREFIX}/share/rootcheck/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/rootcheck/db/
	${INSTALL_DATA} ${WRKSRC}/db/*.txt ${DESTDIR}${PREFIX}/share/rootcheck/db/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/rootcheck
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/rootcheck/

.include "../../mk/bsd.pkg.mk"
