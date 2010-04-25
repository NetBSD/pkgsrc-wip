# $NetBSD: Makefile,v 1.9 2010/04/25 12:15:27 asau Exp $

DISTNAME=	zabbix-1.8.1
PKGREVISION=	#
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zabbix/}

MAINTAINER=	pkgsrc-wip-discuss@lists.sourceforge.net
HOMEPAGE=	http://www.zabbix.com/
COMMENT=	Network monitoring tool

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no
USE_TOOLS+=		makeinfo pax

#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CONFIGURATION_FILES=	zabbix_agent.conf zabbix_agentd.conf zabbix_proxy.conf zabbix_server.conf

PKG_SYSCONFSUBDIR=	zabbix
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
#CONF_FILES=		${EGDIR}/... ${PKG_SYSCONFDIR}/...
#EGDIR=			${PREFIX}/share/examples/zabbix
CONF_FILES=		${EGDIR}/zabbix_agent.conf ${PKG_SYSCONFDIR}/zabbix_agent.conf
CONF_FILES+=		${EGDIR}/zabbix_agentd.conf ${PKG_SYSCONFDIR}/zabbix_agentd.conf
CONF_FILES+=		${EGDIR}/zabbix_proxy.conf ${PKG_SYSCONFDIR}/zabbix_trapper.conf
CONF_FILES+=		${EGDIR}/zabbix_server.conf ${PKG_SYSCONFDIR}/zabbix_server.conf
INSTALLATION_DIRS+=	${EGDIR}

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

OWN_DIRS+=	share/zabbix share/zabbix/data share/zabbix/schema share/examples/zabbix share/doc/zabbix

RCD_SCRIPTS=	zabbix_agentd zabbix_server
.for script in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${script}=	${WRKSRC}/misc/init.d/freebsd/${script}
.endfor

# necessary SQL scripts
SQL_SCRIPTS_DIR=	${WRKSRC}/create
SQL_SCRIPTS+=	data/data.sql
SQL_SCRIPTS+=	data/images_oracle.sql data/images_pgsql.sql
SQL_SCRIPTS+=	data/images_mysql.sql data/images_sqlite3.sql
SQL_SCRIPTS+=	schema/oracle.sql schema/postgresql.sql
SQL_SCRIPTS+=	schema/mysql.sql schema/sqlite.sql

CHECK_INTERPRETER_SKIP=	share/zabbix/upgrades/dbpatches/1.8/mysql/upgrade
CHECK_WRKREF_SKIP=	share/zabbix/upgrades/Makefile

post-install:
.for d in ${OWN_DIRS}
	mkdir ${DESTDIR}${PREFIX}/$d
.endfor
# documentation
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${PREFIX}/share/doc/zabbix/
.for f in ${CONFIGURATION_FILES}
	${INSTALL_DATA} ${WRKSRC}/misc/conf/$f ${DESTDIR}${EGDIR}/$f
.endfor
.for f in ${SQL_SCRIPTS}
	${INSTALL_DATA} ${SQL_SCRIPTS_DIR}/$f ${DESTDIR}${PREFIX}/share/zabbix/$f
.endfor
.for f in AUTHORS COPYING FAQ INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${DESTDIR}${PREFIX}/share/doc/zabbix/$f
.endfor
	cd ${WRKSRC}; pax -rw frontends upgrades ${DESTDIR}${PREFIX}/share/zabbix/

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
