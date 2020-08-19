# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:53 jperkin Exp $

COLLECTD_PACKAGE=	notify-email

COMMENT=		Statistics collection daemon - notify_email plugin

.include "../../mail/libesmtp/buildlink3.mk"
COLLECTD_LIB.esmtp=	${BUILDLINK_PREFIX.libesmtp}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
