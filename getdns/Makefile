# $NetBSD$

DISTNAME=	getdns-1.1.0
CATEGORIES=	net
MASTER_SITES=	https://getdnsapi.net/releases/getdns-1-1-0/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://getdnsapi.net/releases/getdns-1-1-0/
COMMENT=	Modern asynchronous DNS API
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	getdns.pc.in
PKGCONFIG_OVERRIDE+=	getdns_ext_event.pc.in

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../net/unbound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
