# $NetBSD: Makefile,v 1.2 2005/03/24 21:13:28 thomasklausner Exp $

DISTNAME=	fragrouter-1.6
CATEGORIES=	security
# XXX: mastersite disappeared in October 2002
# XXX: MASTER_SITES=	http://www.anzen.com/research/nidsbench/
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	packages@NetBSD.org
# XXX: HOMEPAGE=	http://www.anzen.com/research/nidsbench/
COMMENT=	Tool for testing network IDS implementations

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
