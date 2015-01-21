# $NetBSD: Makefile,v 1.1 2015/01/21 22:56:43 heidnes Exp $

PKG_OPTIONS+=	zabbix-server
PKGNAME=	zabbix-proxy-pgsql-${VER}

.include "../../wip/zabbix/Makefile.common"

CONFIGURE_ARGS+=--disable-agent
CONFIGURE_ARGS+=--disable-server

CONFIGURE_ARGS+=--enable-proxy
CONFIGURE_ARGS+=--with-postgresql

CONF_FILES+=	${EGDIR}/zabbix_proxy.conf ${PKG_SYSCONFDIR}/zabbix_proxy.conf

RCD_SCRIPTS=	zabbix_proxy

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
