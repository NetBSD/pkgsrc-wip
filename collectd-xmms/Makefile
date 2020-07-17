# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	xmms

COMMENT=		Statistics collection daemon - xmms plugin

.include "../../audio/xmms/buildlink3.mk"
COLLECTD_LIB.xmms=	${BUILDLINK_PREFIX.xmms}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
