# $NetBSD$

DISTNAME=	getdns-1.5.2
CATEGORIES=	net
MASTER_SITES=	https://getdnsapi.net/dist/

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://getdnsapi.net/
COMMENT=	Modern asynchronous DNS API
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	getdns.pc.in
PKGCONFIG_OVERRIDE+=	getdns_ext_event.pc.in

CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../net/unbound/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
