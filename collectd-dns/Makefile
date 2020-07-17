# $NetBSD: Makefile,v 1.5 2020/02/03 09:12:32 triaxx Exp $

COLLECTD_PACKAGE=	dns

COMMENT=		Statistics collection daemon - dns plugin
PKGREVISION=		3

.include "../../net/libpcap/buildlink3.mk"
COLLECTD_LIB.pcap=	${BUILDLINK_PREFIX.libpcap}

.include "../../wip/collectd/Makefile.common"

# On NetBSD, built-in pcap lacks headers needed
.if ${OPSYS} == "NetBSD"
PREFER.libpcap=	pkgsrc
.endif

.include "../../mk/bsd.pkg.mk"
