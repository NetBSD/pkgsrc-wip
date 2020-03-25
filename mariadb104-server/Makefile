# $NetBSD$

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	MariaDB 10.4, a free SQL database (server)

CONFLICTS=	mysql-server-[0-9]*

.include "../../wip/mariadb104-client/Makefile.common"

# We only need readline to placate the configure script if we don't build
# the embedded server as it is the only binary linked against "readline".
BUILDLINK_DEPMETHOD.readline=	build

CMAKE_ARGS+=		-DPYTHON_SHEBANG=${PYTHONBIN}

PLIST_VARS+=		embedded

.include "../../mk/bsd.fast.prefs.mk"

MYSQL_USER?=		mysql
MYSQL_GROUP?=		mysql
MYSQL_PIDFILE?=		${MYSQL_DATADIR}/${HOST}.pid

PKG_USERS_VARS+=	MYSQL_USER
PKG_GROUPS_VARS+=	MYSQL_GROUP

PKG_GROUPS=		${MYSQL_GROUP}
PKG_USERS=		${MYSQL_USER}:${MYSQL_GROUP}

PKG_GECOS.${MYSQL_USER}=	MariaDB administrator
PKG_HOME.${MYSQL_USER}=		${MYSQL_DATADIR}
PKG_SHELL.${MYSQL_USER}=	${SH}

RCD_SCRIPTS=		mariadb
SMF_NAME=		mariadb
SMF_METHODS=		${RCD_SCRIPTS}

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
FILES_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
FILES_SUBST+=		MYSQL_PIDFILE=${MYSQL_PIDFILE}
MESSAGE_SUBST+=		MYSQL_DATADIR=${MYSQL_DATADIR}
MESSAGE_SUBST+=		MYSQL_USER=${MYSQL_USER} MYSQL_GROUP=${MYSQL_GROUP}
BUILD_DEFS+=		MYSQL_DATADIR

.include "../../archivers/lz4/buildlink3.mk"
.include "../../wip/mariadb104-client/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../devel/msgpack/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
