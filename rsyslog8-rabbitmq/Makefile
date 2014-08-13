# $NetBSD: Makefile,v 1.1 2014/08/13 10:51:05 fhajny Exp $
#

RSYSLOG_MOD=	rabbitmq
PKGNAME=	${DISTNAME:S/rsyslog/rsyslog-${RSYSLOG_MOD}/}

DEPENDS+=	rsyslog>=${PKGVERSION_NOREV}:../../wip/rsyslog8

.include "../../wip/rsyslog8/Makefile.common"

CONFIGURE_ARGS+=	--enable-omrabbitmq

BUILD_DIRS=		plugins/omrabbitmq

.include "../../net/rabbitmq-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
