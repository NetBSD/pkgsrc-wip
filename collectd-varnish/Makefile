# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	varnish

COMMENT=		Statistics collection daemon - varnish plugin

.include "../../www/varnish/buildlink3.mk"
COLLECTD_LIB.varnish=	${BUILDLINK_PREFIX.varnish}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
