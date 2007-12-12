# $NetBSD: Makefile,v 1.3 2007/12/12 21:48:10 asau Exp $

DISTNAME=	zabbix-1.4.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zabbix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zabbix.com/
COMMENT=	Network monitoring tool

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	zabbix
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
#CONF_FILES=		${EGDIR}/... ${PKG_SYSCONFDIR}/...
#EGDIR=			${PREFIX}/share/examples/zabbix
CONF_FILES=		${EGDIR}/zabbix_agent.conf ${PKG_SYSCONFDIR}/zabbix_agent.conf
CONF_FILES+=		${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf
CONF_FILES+=		${EGDIR}/zabbix_server.conf ${PKG_SYSCONFDIR}/zabbix_server.conf
CONF_FILES+=		${EGDIR}/zabbix_trapper.conf ${PKG_SYSCONFDIR}/zabbix_trapper.conf

# ZABBIX user account
ZBXUSER?=		zabbix
ZBXGROUP?=		zabbix
ZBXHOME?=		/home/${ZBXUSER}	# ${PREFIX}/${USER}
FILES_SUBST+=		ZBXUSER=${ZBXUSER}
FILES_SUBST+=		ZBXGROUP=${ZBXGROUP}
FILES_SUBST+=		ZBXHOME=${ZBXHOME}
BUILD_DEFS+=		ZBXHOME

PKG_GROUPS_VARS+=	ZBXGROUP
PKG_USERS_VARS+=	ZBXUSER

PKG_GROUPS=		${ZBXGROUP}
PKG_USERS=		${ZBXUSER}:${ZBXGROUP}
PKG_GECOS.${PGUSER}=	ZABBIX monitoring pseudo-user
PKG_HOME.${PGUSER}=	${ZBXHOME}
PKG_SHELL.${PGUSER}=	${SH}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute pathes.
SUBST_FILES.fix-paths=		src/zabbix_server/server.c src/zabbix_agent/zabbix_agent.c
SUBST_SED.fix-paths=		-e 's,"@PREFIX@,"${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,"@HOMEDIR@,"${ZBXHOME},g'
SUBST_SED.fix-paths+=		-e 's,"@CONFDIR@,"${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,"@SCRIPTDIR@,"${PREFIX}/libexec/${PKGNAME_NOREV},g'
SUBST_SED.fix-paths+=		-e 's,"@PIDDIR@,"${VARBASE}/run,g'

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
