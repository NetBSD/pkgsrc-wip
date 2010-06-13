# $NetBSD: Makefile,v 1.5 2010/06/13 22:46:57 thomasklausner Exp $
#

DISTNAME=		cacti-0.8.7e
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://sourceforge.net/project/showfiles.php?group_id=34886&package_id=27259

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.cacti.net/
COMMENT=		Frontend to rrdtool for monitoring systems and services
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/${DISTNAME}

#DEPENDS+=		${PHP_PKG_PREFIX}>=4.3.6:../../lang/php
DEPENDS+=		php>=5:../../lang/php5
DEPENDS+=		rrdtool>=1.0.49:../../databases/rrdtool
DEPENDS+=		mysql-server>=4.1:../../databases/mysql5-server
DEPENDS+=		net-snmp>=5.1.2:../../net/net-snmp

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_GROUPS_VARS+=	CACTI_GROUP
PKG_USERS_VARS+=	CACTI_USER

CACTI_USER?=		cacti
CACTI_GROUP?=		cacti

PKG_GROUPS=		${CACTI_GROUP}
PKG_USERS=		${CACTI_USER}:${CACTI_GROUP}
PKG_GECOS.${CACTI_USER}=	Cacti user
PKG_HOME.${CACTI_USER}=	${CACTIDIR}
PKG_SHELL.${CACTI_USER}=	${SH}
PKG_USERS_VARS+=	CACTI_USER
PKG_GROUPS_VARS+=	CACTI_GROUP

EGDIR=			${PREFIX}/share/examples/cacti
CACTIDIR=		${PREFIX}/share/cacti
LOGDIR=			${CACTIDIR}/log
RRADIR=			${CACTIDIR}/rra

MESSAGE_SUBST+=         CACTIDIR=${CACTIDIR}
MESSAGE_SUBST+=         LOGDIR=${LOGDIR}
MESSAGE_SUBST+=         CACTI_USER=${CACTI_USER}
FILES_SUBST+=		CACTIDIR=${CACTIDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/cacti.conf
SUBST_VARS.paths+=	CACTIDIR
SUBST_STAGE.paths=	post-patch

OWN_DIRS_PERMS+=        ${LOGDIR} ${CACTI_USER} ${CACTI_GROUP} 755
OWN_DIRS_PERMS+=        ${RRADIR} ${CACTI_USER} ${CACTI_GROUP} 755

INSTALLATION_DIRS=      share/examples/cacti
INSTALLATION_DIRS+=	share/cacti

post-extract:
	${CP} ${FILESDIR}/cacti.conf ${WRKDIR}/
	${CP} ${FILESDIR}/bsd_memory.pl ${WRKSRC}/scripts/

do-install:
	${INSTALL_DATA} ${WRKDIR}/cacti.conf ${DESTDIR}${EGDIR}/cacti.conf
	${CP} -R ${WRKSRC}/* ${DESTDIR}${CACTIDIR}
	#${CHOWN} ${CACTI_USER}:${CACTI_GROUP} ${DESTDIR}${RRADIR}
	#${CHOWN} ${CACTI_USER}:${CACTI_GROUP} ${DESTDIR}${LOGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
