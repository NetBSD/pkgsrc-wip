# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:52 jperkin Exp $

COLLECTD_PACKAGE=	amqp

COMMENT=		Statistics collection daemon - amqp plugin
PKGREVISION=		3

.include "../../net/rabbitmq-c/buildlink3.mk"
COLLECTD_LIB.rabbitmq=	${BUILDLINK_PREFIX.rabbitmq-c}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
