# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	gmond

COMMENT=		Statistics collection daemon - gmond plugin

.include "../../parallel/ganglia-monitor-core/buildlink3.mk"
COLLECTD_LIB.ganglia=	${BUILDLINK_PREFIX.ganglia-monitor-core}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
