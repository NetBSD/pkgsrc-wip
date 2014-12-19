# $NetBSD: Makefile,v 1.1 2014/12/19 13:57:28 heidnes Exp $

.include "../../wip/zabbix/Makefile.common"

PKGNAME=		zabbix-agent-${VER}

CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--disable-server

CONF_FILES=	${EGDIR}/zabbix_agent.conf ${PKG_SYSCONFDIR}/zabbix_agent.conf
CONF_FILES+=	${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf

RCD_SCRIPTS=	zabbix_agentd
# .for script in ${RCD_SCRIPTS}
# RCD_SCRIPT_SRC.${script}=	${WRKSRC}/misc/init.d/freebsd/${script}
# .endfor

.include "../../mk/bsd.pkg.mk"
