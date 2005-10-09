# $NetBSD: Makefile,v 1.4 2005/10/09 23:27:12 rillig Exp $
#

DISTNAME=		cvsreport-0.3.5
CATEGORIES=		sysutils
MASTER_SITES=		http://download.gna.org/cvsreport/cvsreport.pkg/0.3.5/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://home.gna.org/report/
COMMENT=		Message reports from CVS activity

REPLACE_PERL+=		cvsreport
USE_TOOLS+=		perl:run
NO_BUILD=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsreport ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cvsreport.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
