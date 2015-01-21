# $NetBSD: Makefile,v 1.1 2015/01/21 22:56:43 heidnes Exp $

PKG_OPTIONS+=	zabbix-server
PKGNAME=	zabbix-proxy-mysql-${VER}

.include "../../wip/zabbix/Makefile.common"

CONFIGURE_ARGS+=--disable-agent
CONFIGURE_ARGS+=--disable-server

CONFIGURE_ARGS+=--enable-proxy
CONFIGURE_ARGS+=--with-mysql

CONF_FILES+=	${EGDIR}/zabbix_proxy.conf ${PKG_SYSCONFDIR}/zabbix_proxy.conf

RCD_SCRIPTS=	zabbix_proxy

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
