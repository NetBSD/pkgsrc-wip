# $NetBSD: Makefile,v 1.1.1.1 2004/05/13 08:45:10 poppnk Exp $
#

DISTNAME=		stmpclean-0.3
CATEGORIES=		wip sysutils
MASTER_SITES=		http://www.internet2.edu/~shalunov/stmpclean/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.internet2.edu/~shalunov/stmpclean/
COMMENT=		Secure /tmp cleaner

USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${PREFIX}/man/man8/

.include "../../mk/bsd.pkg.mk"
