# $NetBSD: Makefile,v 1.3 2019/08/11 13:23:05 wiz Exp $

COLLECTD_PACKAGE=	mysql

PKGNAME=		${DISTNAME:S/collectd/collectd-${COLLECTD_PACKAGE}${MYSQL_VERSION}/}
COMMENT=		Statistics collection daemon - mysql plugin

.include "../../mk/mysql.buildlink3.mk"
COLLECTD_LIB.mysql=	${BUILDLINK_PREFIX.mysql-client}

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
