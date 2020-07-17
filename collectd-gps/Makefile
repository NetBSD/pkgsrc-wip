# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	gps

COMMENT=		Statistics collection daemon - gps plugin

.include "../../geography/gpsd/buildlink3.mk"
COLLECTD_LIB.gps=	${BUILDLINK_PREFIX.gpsd}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
