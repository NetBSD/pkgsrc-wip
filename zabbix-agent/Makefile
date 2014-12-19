# $NetBSD: Makefile,v 1.2 2014/12/19 14:12:24 heidnes Exp $

.include "../../wip/zabbix/Makefile.common"

PKGNAME=		zabbix-agent-${VER}

CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--disable-server

CONF_FILES+=	${EGDIR}/zabbix_agent.conf ${PKG_SYSCONFDIR}/zabbix_agent.conf
CONF_FILES+=	${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf

RCD_SCRIPTS=	zabbix_agentd

.include "../../mk/bsd.pkg.mk"
