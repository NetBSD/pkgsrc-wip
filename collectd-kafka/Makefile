# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	kafka
COLLECTD_PLUGINS=	write_kafka

COMMENT=		Statistics collection daemon - write_kafka plugin

.include "../../devel/librdkafka/buildlink3.mk"
COLLECTD_LIB.rdkafka=	${BUILDLINK_PREFIX.librdkafka}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
