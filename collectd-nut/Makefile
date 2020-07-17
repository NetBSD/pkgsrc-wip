# $NetBSD: Makefile,v $

COLLECTD_PACKAGE=	nut

COMMENT=		Statistics collection daemon - nut plugin

.include "../../sysutils/ups-nut/buildlink3.mk"
COLLECTD_LIB.upsclient=	${BUILDLINK_PREFIX.ups-nut}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
