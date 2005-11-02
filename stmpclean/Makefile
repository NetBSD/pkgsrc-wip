# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:27 thomasklausner Exp $
#

DISTNAME=		stmpclean-0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.internet2.edu/~shalunov/stmpclean/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.internet2.edu/~shalunov/stmpclean/
COMMENT=		Secure /tmp cleaner


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
