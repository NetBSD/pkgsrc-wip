# $NetBSD: Makefile,v 1.37 2020/06/20 12:43:46 gdt Exp $

.include "../../sysutils/zabbix50-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-agent-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-agent
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libcurl
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

EGDIR=		share/examples/zabbix
CONF_FILES+=	${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf

RCD_SCRIPTS=	zabbix_agentd

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

.include "../../mk/bsd.prefs.mk"

ZABBIX_GROUP?=		zabbix
ZABBIX_USER?=		zabbix
ZABBIX_HOMEDIR?=	/var/zabbix
PKG_GROUPS+=		${ZABBIX_GROUP}
PKG_USERS+=		${ZABBIX_USER}:${ZABBIX_GROUP}
PKG_GECOS.${ZABBIX_USER}= Zabbix user
PKG_HOME.${ZABBIX_USER}=	${ZABBIX_HOMEDIR}

FILES_SUBST+=		ZABBIX_USER=${ZABBIX_USER}
FILES_SUBST+=		ZABBIX_GROUP=${ZABBIX_GROUP}

OWN_DIRS_PERMS+=	${ZABBIX_HOMEDIR} ${ZABBIX_USER} ${ZABBIX_GROUP} 0755

SMF_INSTANCES=		agent

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
