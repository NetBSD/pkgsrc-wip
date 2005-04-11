# $NetBSD: Makefile,v 1.4 2005/04/11 21:16:00 tvierling Exp $

DISTNAME=		tcpdump-3.8.3
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		imil@gcu.info
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		Network monitoring tool

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PREFER_PKGSRC=		yes

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../wip/libpcap-latest/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
