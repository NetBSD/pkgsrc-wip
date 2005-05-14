# $NetBSD: Makefile,v 1.1.1.1 2005/05/14 02:44:39 poppnk Exp $
#

DISTNAME=		PingTunnel-0.60
PKGNAME=		ptunnel-0.60
CATEGORIES=		wip net
MASTER_SITES=		http://www.cs.uit.no/~daniels/PingTunnel/ \
			http://dag.wieers.com/packages/ptunnel/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cs.uit.no/~daniels/PingTunnel/
COMMENT=		TCP tunnel over ICMP

WRKSRC=			${WRKDIR}/PingTunnel
USE_GNU_TOOLS+=		make

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
