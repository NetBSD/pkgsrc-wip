# $NetBSD: Makefile,v 1.7 2019/08/11 13:23:05 wiz Exp $

COLLECTD_PACKAGE=	postgresql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${PGSQL_VERSION}/}
COMMENT=		Statistics collection daemon - postgresql plugin

.include "../../mk/pgsql.buildlink3.mk"
COLLECTD_LIB.pq=	${PGSQL_PREFIX}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
