# $NetBSD: Makefile,v 1.6 2012/12/04 21:07:43 othyro Exp $
#

DISTNAME=	PingTunnel-0.72
PKGNAME=	${DISTNAME:tl:S/ing//1}
CATEGORIES=	net
MASTER_SITES=	http://www.cs.uit.no/~daniels/PingTunnel/ \
		http://dag.wieers.com/packages/ptunnel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.uit.no/~daniels/PingTunnel/
COMMENT=	TCP tunnel over ICMP
LICENSE=	modified-bsd

# XXX Could be patched to use net/if_ether.h
NOT_FOR_PLATFORM=	NetBSD-*-* # XXX needs net/ethernet.h

WRKSRC=		${WRKDIR}/PingTunnel
USE_TOOLS+=	gmake

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
