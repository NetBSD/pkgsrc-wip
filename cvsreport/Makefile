# $NetBSD: Makefile,v 1.2 2004/07/18 15:50:18 ppostma Exp $
#

DISTNAME=		cvsreport-0.3.5
CATEGORIES=		sysutils
MASTER_SITES=		http://download.gna.org/cvsreport/cvsreport.pkg/0.3.5/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://home.gna.org/report/
COMMENT=		Message reports from CVS activity

REPLACE_PERL+=		cvsreport
USE_PERL5=		yes
USE_BUILDLINK3=		yes
NO_BUILD=#

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsreport ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cvsreport.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
