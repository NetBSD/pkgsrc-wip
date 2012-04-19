# $NetBSD: Makefile,v 1.1.1.1 2012/04/19 10:31:37 fhajny Exp $
#

.include "Makefile.common"

PKGNAME=		${DISTNAME:S/keeper/keeper-server/}
COMMENT=		Highly reliable distributed coordination server

USE_JAVA=		yes
USE_JAVA2=		yes

BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant
BUILD_DEPENDS+=		apache-ivy-[0-9]*:../../devel/apache-ivy
BUILD_DEPENDS+=		apache-maven-[0-9]*:../../devel/apache-maven

PKG_SYSCONFSUBDIR=	zookeeper

.include "../../mk/bsd.prefs.mk"

ZK_DB?=			${VARBASE}/db/zookeeper
ZK_LOG?=		${VARBASE}/log/zookeeper
ZK_RUN?=		${VARBASE}/run/zookeeper
ZK_USER?=		zookeeper
ZK_GROUP?=		hadoop

BUILD_DEFS+=		VARBASE ZK_DB ZK_LOG ZK_RUN ZK_USER ZK_GROUP

PKG_GROUPS+=		${ZK_GROUP}
PKG_USERS+=		${ZK_USER}:${ZK_GROUP}

PKG_GECOS.${ZK_USER}=	ZooKeeper Daemon User
PKG_HOME.${ZK_USER}=	${PREFIX}/share/zookeeper
PKG_SHELL.${ZK_USER}=	${BASH}

OWN_DIRS+=		${ZK_DB} ${ZK_DB}/data ${ZK_LOG} ${ZK_RUN}
OWN_DIRS_PERMS+=	${ZK_DB} ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_DB} ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_LOG} ${ZK_USER} ${ZK_GROUP} 755
OWN_DIRS_PERMS+=	${ZK_RUN} ${ZK_USER} ${ZK_GROUP} 755

BUILDDIR=		${WRKSRC}/build/${DISTNAME}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing ZooKeeper default paths
SUBST_FILES.paths=	conf/zoo_sample.cfg
SUBST_FILES.paths+=	src/packages/templates/conf/zookeeper-env.sh
SUBST_VARS.paths+=	PKG_JAVA_HOME ZK_DB ZK_LOG ZK_RUN

REPLACE_BASH=		bin/zkCli.sh bin/zkEnv.sh bin/zkServer.sh

INSTALLATION_DIRS+=	bin libexec sbin share/examples/zookeeper share/zookeeper

CONF_FILES+=		share/examples/zookeeper/configuration.xsl ${PKG_SYSCONFDIR}/configuration.xsl
CONF_FILES+=		share/examples/zookeeper/log4j.properties ${PKG_SYSCONFDIR}/log4j.properties
CONF_FILES+=		share/examples/zookeeper/zoo.cfg ${PKG_SYSCONFDIR}/zoo.cfg
CONF_FILES+=		share/examples/zookeeper/zookeeper-env.sh ${PKG_SYSCONFDIR}/zookeeper-env.sh

do-build:
	cd ${WRKSRC} && ${SETENV} JAVA_HOME=${PKG_JAVA_HOME} ant bin-package

do-install:
	${INSTALL_SCRIPT} ${BUILDDIR}/bin/zkCli.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${BUILDDIR}/libexec/zkEnv.sh ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${BUILDDIR}/sbin/zkServer.sh ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${BUILDDIR}/conf/configuration.xsl ${DESTDIR}${PREFIX}/share/examples/zookeeper
	${INSTALL_DATA} ${BUILDDIR}/conf/log4j.properties ${DESTDIR}${PREFIX}/share/examples/zookeeper
	${INSTALL_DATA} ${BUILDDIR}/conf/zoo_sample.cfg ${DESTDIR}${PREFIX}/share/examples/zookeeper/zoo.cfg
	${INSTALL_DATA} ${BUILDDIR}/share/zookeeper/templates/conf/zookeeper-env.sh \
		${DESTDIR}${PREFIX}/share/examples/zookeeper/zookeeper-env.sh
	${CP} -Rp ${BUILDDIR}/share/zookeeper/* ${DESTDIR}${PREFIX}/share/zookeeper/
	${RM} -f ${DESTDIR}${PREFIX}/share/zookeeper/templates/conf/zookeeper-env.sh.orig

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
