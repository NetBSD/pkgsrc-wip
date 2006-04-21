# $NetBSD: Makefile,v 1.4 2006/04/21 07:31:48 cheusov Exp $
#

DISTNAME=		stmpclean-0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.internet2.edu/~shalunov/stmpclean/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.internet2.edu/~shalunov/stmpclean/
COMMENT=		Secure /tmp cleaner


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stmpclean ${PREFIX}/sbin/stmpclean
	${INSTALL_DATA} ${WRKSRC}/stmpclean.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
