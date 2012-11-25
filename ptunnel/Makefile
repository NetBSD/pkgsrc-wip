# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=		PingTunnel-0.60
PKGNAME=		ptunnel-0.60
CATEGORIES=		net
MASTER_SITES=		http://www.cs.uit.no/~daniels/PingTunnel/ \
			http://dag.wieers.com/packages/ptunnel/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.uit.no/~daniels/PingTunnel/
COMMENT=		TCP tunnel over ICMP

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/PingTunnel
USE_TOOLS+=		gmake

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
