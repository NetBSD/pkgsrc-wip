# $NetBSD: Makefile,v 1.29 2021/12/09 17:50:16 bsiegert Exp $

DISTNAME=	influxdb-2.5.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=influxdata/}
MASTER_SITES+=	${MASTER_SITE_GITHUB:=influxdata/ui/releases/download/OSS-Master/}
CATEGORIES=	databases
GITHUB_PROJECT=	influxdb
GITHUB_TAG=	v${PKGVERSION_NOREV}

DIST_SUBDIR=	influxdata
DISTFILES=	${PKGNAME_NOREV}${EXTRACT_SUFX}
DISTFILES+=	build.tar.gz

EXTRACT_DIR.build.tar.gz=	${WRKSRC}/static/data

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/influxdata/influxdb
COMMENT=	Scalable datastore for metrics, events, and real-time analytics
LICENSE=	mit

# XXX Building of libflux (Rust implementation of a Flux parser) makes references
#     of ${FAKEHOMEDIR}/.cargo in influxd binary.
CHECK_WRKREF=	no

BUILD_DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

USE_TOOLS=	pkg-config

DATADIR=	${VARBASE}/lib/influxdb
LOGDIR=		${VARBASE}/log/influxdb

BUILD_DEFS+=		INFLUXDB_USER INFLUXDB_GROUP VARBASE
FILES_SUBST+=		INFLUXDB_USER=${INFLUXDB_USER:Q}
FILES_SUBST+=		INFLUXDB_GROUP=${INFLUXDB_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

INFLUXDB_USER?=		influxdb
INFLUXDB_GROUP?=	influxdb
OWN_DIRS_PERMS+=	${DATADIR} ${INFLUXDB_USER} ${INFLUXDB_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${INFLUXDB_USER} ${INFLUXDB_GROUP} 0700
PKG_USERS_VARS+=	INFLUXDB_USER
PKG_GROUPS_VARS+=	INFLUXDB_GROUP
PKG_GROUPS=		${INFLUXDB_GROUP}
PKG_USERS=		${INFLUXDB_USER}:${INFLUXDB_GROUP}
PKG_SYSCONFSUBDIR=	influxdb
RCD_SCRIPTS=		influxdb

INSTALLATION_DIRS+=	sbin

.include "go-modules.mk"

INFLUX_GO_FLAGS=	-s
INFLUX_GO_FLAGS+=	-X main.version=${PKGVERSION_NOREV}
INFLUX_GO_FLAGS+=	-X main.commit=${GITHUB_TAG}
INFLUX_GO_FLAGS+=	-X main.branch=${PKGVERSION_NOREV}
INFLUX_GO_FLAGS+=	-X main.buildstamp=pkgsrc

PKG_CONFIG=		${WRKDIR}/.gopath/bin/pkg-config

pre-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GO} install -v github.com/influxdata/pkg-config
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${GO} generate -tags "assets" ./static

# XXX Remove TOOLS_DIR from path to avoid pkg-config being executed instead of
#     Go pkg-config wrapper.
do-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		PKG_CONFIG=${PKG_CONFIG:Q} PATH=${PATH:S|${TOOLS_DIR}/bin||:Q} \
		${GO} build -ldflags "${INFLUX_GO_FLAGS}" \
		-tags "assets,sqlite_foreign_keys,sqlite_json" ./cmd/influxd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/influxd ${DESTDIR}${PREFIX}/sbin/influxd

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
