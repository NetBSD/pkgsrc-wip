# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:05 wiz Exp $

COLLECTD_PACKAGE=	memcachec

COMMENT=		Statistics collection daemon - memcachec plugin
PKGREVISION=		2

.include "../../devel/libmemcached/buildlink3.mk"
COLLECTD_LIB.memcached=	${BUILDLINK_PREFIX.libmemcached}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
