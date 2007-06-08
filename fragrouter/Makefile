# $NetBSD: Makefile,v 1.5 2007/06/08 21:32:22 thomasklausner Exp $

DISTNAME=	fragrouter-1.6
CATEGORIES=	security
# XXX: mastersite disappeared in October 2002
# XXX: MASTER_SITES=	http://www.anzen.com/research/nidsbench/
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
# XXX: HOMEPAGE=	http://www.anzen.com/research/nidsbench/
COMMENT=	Tool for testing network IDS implementations

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet10}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

SUBST_CLASSES+=		net
SUBST_STAGE.net=	pre-configure
SUBST_FILES.net=	configure Makefile.in
SUBST_SED.net=		-e 's/libnet-config/libnet10-config/'
SUBST_MESSAGE.net=	Fix libnet-config name.

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
