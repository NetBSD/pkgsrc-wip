# $NetBSD: Makefile,v 1.2 2005/04/11 21:15:57 tvierling Exp $
#

DISTNAME=		stmpclean-0.3
CATEGORIES=		wip sysutils
MASTER_SITES=		http://www.internet2.edu/~shalunov/stmpclean/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.internet2.edu/~shalunov/stmpclean/
COMMENT=		Secure /tmp cleaner


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
