# $NetBSD: Makefile,v 1.2 2004/12/02 16:38:57 thomasklausner Exp $
#

DISTNAME=		balance-3.15
CATEGORIES=		wip net
MASTER_SITES=		http://www.inlab.de/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.inlab.de/balance.html
COMMENT=		TCP loadbalancer with roundrobin and failover

USE_BUILDLINK3=		yes

BUILD_TARGET=balance

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/balance ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/balance.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
