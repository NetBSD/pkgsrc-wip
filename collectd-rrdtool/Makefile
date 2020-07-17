# $NetBSD: Makefile,v 1.17 2020/06/02 08:24:44 adam Exp $

COLLECTD_PACKAGE=	rrdtool
COLLECTD_PLUGINS=	rrdtool rrdcached

COMMENT=		Statistics collection daemon - rrdtool plugins
PKGREVISION=		9

.include "../../databases/rrdtool/buildlink3.mk"
COLLECTD_LIB.rrd=	${BUILDLINK_PREFIX.rrdtool}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
