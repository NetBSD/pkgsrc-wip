# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:53 jperkin Exp $

COLLECTD_PACKAGE=	snmp

COMMENT=		Statistics collection daemon - snmp plugin

.include "../../net/net-snmp/buildlink3.mk"
COLLECTD_LIB.netsnmp=	${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config

.include "../../wip/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
