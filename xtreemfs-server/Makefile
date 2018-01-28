# $NetBSD: Makefile,v 1.1.1.1 2011/11/08 01:42:14 tnn2 Exp $
#
BUILD_DEPENDS+=		apache-ant-[0-9]*:../../devel/apache-ant

PKGNAME=		${DISTNAME:S/XtreemFS/xtreemfs-server/}

USE_LANGUAGES=		# only Java for the server

MAKE_ENV+=		ANT_HOME=${PREFIX}

XTREEMFS_USER?=		xtreemfs
XTREEMFS_GROUP?=	xtreemfs
XTREEMFS_HOME?=		${VARBASE}/lib/xtreemfs
BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		XTREEMFS_HOME

PKG_GROUPS_VARS+=	XTREEMFS_GROUP
PKG_USERS_VARS+=	XTREEMFS_USER

PKG_GROUPS=			${XTREEMFS_GROUP}
PKG_USERS=			${XTREEMFS_USER}:${XTREEMFS_GROUP}
PKG_GECOS.${XTREEMFS_USER}=	XtreemFS daemon user
PKG_HOME.${XTREEMFS_USER}=	${XTREEMFS_HOME}

RCD_SCRIPTS+=		xtreemfs_dir xtreemfs_mrc xtreemfs_osd

FILES_SUBST+=		JAVA=${PKG_JAVA_HOME}/bin/java
FILES_SUBST+=		XTREEMFS_USER=${XTREEMFS_USER}
JAVA_LIB=		${PREFIX}/share/xtreemfs/java/lib
FILES_SUBST+=		CLASSPATH=${JAVA_LIB}/XtreemFS.jar:${JAVA_LIB}/BabuDB.jar:${JAVA_LIB}/Flease.jar:${JAVA_LIB}/protobuf-java-2.3.0.jar:${JAVA_LIB}/Foundation.jar:${JAVA_LIB}/jdmkrt.jar:${JAVA_LIB}/jdmktk.jar

OWN_DIRS_PERMS+=	${XTREEMFS_HOME} ${XTREEMFS_USER} ${XTREEMFS_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/xtreemfs ${XTREEMFS_USER} ${XTREEMFS_GROUP} 0750

PKG_SYSCONFSUBDIR=	xtreemfs
EGDIR=			${PREFIX}/share/examples/xtreemfs

CONF_FILES_PERMS=	${EGDIR}/dirconfig.properties		\
			${PKG_SYSCONFDIR}/dirconfig.properties	\
			${XTREEMFS_USER} ${XTREEMFS_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/mrcconfig.properties		\
			${PKG_SYSCONFDIR}/mrcconfig.properties	\
			${XTREEMFS_USER} ${XTREEMFS_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/osdconfig.properties		\
			${PKG_SYSCONFDIR}/osdconfig.properties	\
			${XTREEMFS_USER} ${XTREEMFS_GROUP} 0640

BUILD_TARGET=		pkgsrc-xtreemfs-server-build
INSTALL_TARGET=		pkgsrc-xtreemfs-server-install

.include "Makefile.common"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
