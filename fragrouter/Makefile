# $NetBSD: Makefile,v 1.3 2005/04/11 21:12:17 tvierling Exp $

DISTNAME=	fragrouter-1.6
CATEGORIES=	security
# XXX: mastersite disappeared in October 2002
# XXX: MASTER_SITES=	http://www.anzen.com/research/nidsbench/
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	packages@NetBSD.org
# XXX: HOMEPAGE=	http://www.anzen.com/research/nidsbench/
COMMENT=	Tool for testing network IDS implementations

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
