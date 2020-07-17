# $NetBSD: Makefile,v 1.1 2014/02/17 11:21:55 fhajny Exp $

COLLECTD_PACKAGE=	redis
COLLECTD_PLUGINS=	redis write_redis

COMMENT=		Statistics collection daemon - redis plugins

.include "../../wip/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libhires=${BUILDLINK_PREFIX.hiredis}

.include "../../databases/hiredis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
