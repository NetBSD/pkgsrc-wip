# $NetBSD$

PKGNAME=	${DISTNAME:S/-/-server-/}
COMMENT=	MariaDB 10.4, a free SQL database (server)

CONFLICTS=	mysql-server-[0-9]*

.include "../../wip/mariadb104-client/Makefile.common"

.if !empty(PKG_OPTIONS:Membedded-server)
CMAKE_ARGS+=			-DWITH_EMBEDDED_SERVER=ON
PLIST_SRC+=			PLIST.embedded
.else
CMAKE_ARGS+=			-DWITH_EMBEDDED_SERVER=OFF
# We only need readline to placate the configure script if we don't build
# the embedded server as it is the only binary linked against "readline".
BUILDLINK_DEPMETHOD.editline=	build
BUILDLINK_DEPMETHOD.readline=	build
.endif

CMAKE_ARGS+=		-DPYTHON_SHEBANG=${PYTHONBIN}

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.fast.prefs.mk"

MARIADB_DATADIR?=	${VARBASE}/db/mariadb
MARIADB_USER?=		mariadb
MARIADB_GROUP?=		mariadb

PKG_USERS_VARS+=	MARIADB_USER
PKG_GROUPS_VARS+=	MARIADB_GROUP

PKG_GROUPS=		${MARIADB_GROUP}
PKG_USERS=		${MARIADB_USER}:${MARIADB_GROUP}

PKG_GECOS.${MARIADB_USER}=	MariaDB administrator
PKG_HOME.${MARIADB_USER}=	${MARIADB_DATADIR}
PKG_SHELL.${MARIADB_USER}=	${SH}

RCD_SCRIPTS=		mariadb
SMF_NAME=		mariadb
SMF_METHODS=		${RCD_SCRIPTS}

FILES_SUBST+=		HOSTNAME_CMD=${HOSTNAME_CMD:Q}
FILES_SUBST+=		MARIADB_DATADIR=${MARIADB_DATADIR}
FILES_SUBST+=		MARIADB_USER=${MARIADB_USER} MARIADB_GROUP=${MARIADB_GROUP}
BUILD_DEFS+=		MARIADB_DATADIR

OWN_DIRS+=		${VARBASE}/run/mariadb ${MARIADB_USER} ${MARIADB_GROUP} 0700
OWN_DIRS+=		${VARBASE}/log/mariadb ${MARIADB_USER} ${MARIADB_GROUP} 0700

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
