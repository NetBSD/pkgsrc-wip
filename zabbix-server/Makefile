# $NetBSD: Makefile,v 1.1 2014/12/19 13:57:28 heidnes Exp $

.include "../../wip/zabbix/Makefile.common"

PKGNAME=		zabbix-server-${VER}

CONFIGURE_ARGS+=	--disable-agent
CONFIGURE_ARGS+=	--enable-server

CONF_FILES+=	${EGDIR}/zabbix_server.conf ${PKG_SYSCONFDIR}/zabbix_server.conf

RCD_SCRIPTS=	zabbix_server

.include "../../mk/bsd.pkg.mk"
