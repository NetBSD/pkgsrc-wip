# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	yajl
COLLECTD_PLUGINS=	ceph log_logstash sysevent

COMMENT=		Statistics collection daemon - YAJL-based plugins

.include "../../devel/yajl/buildlink3.mk"
COLLECTD_LIB.yajl=	${BUILDLINK_PREFIX.yajl}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
