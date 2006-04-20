# $NetBSD: Makefile,v 1.6 2006/04/20 13:36:44 cheusov Exp $
#

DISTNAME=		sleuthkit-1.66
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sleuthkit.sourceforge.net/
COMMENT=		OpenSource Forensic Toolkit

USE_PERL5=		YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sorter ${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/sorter
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mactime ${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/mactime
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/sorter/
	${INSTALL_DATA} ${WRKSRC}/share/sorter/* ${PREFIX}/share/sorter
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sleuthkit/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/sleuthkit/

.include "../../mk/bsd.pkg.mk"
