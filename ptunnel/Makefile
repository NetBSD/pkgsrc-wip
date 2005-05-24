# $NetBSD: Makefile,v 1.2 2005/05/24 10:31:22 rillig Exp $
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
USE_TOOLS+=		gmake

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
