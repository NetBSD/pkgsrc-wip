# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:04 wiz Exp $

COLLECTD_PACKAGE=	dbi

COMMENT=		Statistics collection daemon - dbi plugin

.include "../../databases/libdbi/buildlink3.mk"
COLLECTD_LIB.dbi=	${BUILDLINK_PREFIX.libdbi}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
