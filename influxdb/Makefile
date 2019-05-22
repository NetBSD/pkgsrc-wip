# $NetBSD$

GITHUB_PROJECT=		influxdb
PKGVERSION_NOREV=	1.6.5
DISTNAME=		influxdb-1.6.5
GITHUB_TAG=		v${PKGVERSION_NOREV}
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_GITHUB:=influxdata/}
MAINTAINER=		william@welliver.org
HOMEPAGE=		https://www.influxdata.com/
COMMENT=		Time-series Database
LICENSE=		mit

# despite being the default value, this explicit declaration is required for things
# to build properly.
EXTRACT_SUFX=	.tar.gz

IFDB_DISTNAME=		${DISTNAME}${EXTRACT_SUFX}
IFDB_DEPENDENCIES=	influxdb-dependencies-${PKGVERSION_NOREV}.tar.gz
DISTFILES=		${IFDB_DISTNAME}
.if !defined(BOOTSTRAP)
DISTFILES+=		${IFDB_DEPENDENCIES}
SITES.influxdb-dependencies-${PKGVERSION_NOREV}.tar.gz= https://bitbucket.org/hww3/influxdb/downloads/
.endif

#EXTRACT_ONLY=				${IFDB_DISTNAME}
EXTRACT_DIR.${IFDB_DISTNAME}=		${WRKDIR}/src/github.com/influxdata
EXTRACT_DIR.${IFDB_DEPENDENCIES}=	${WRKDIR}/src/github.com/influxdata
WRKSRC=					${WRKDIR}/src/github.com/influxdata/influxdb
USE_TOOLS+=				gmake curl

BUILD_DEPENDS+=			go19-1.9.*:../../lang/go19
BUILD_DEPENDS+=			asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=			xmlto-[0-9]*:../../textproc/xmlto

# go language executables don't have SSP support
CHECK_SSP_SKIP=	bin/*

PKGSRC_MAKE_ENV+=		GOPATH=${WRKDIR}

PKG_SYSCONFSUBDIR=	influxdb

DATADIR=	${VARBASE}/lib/influxdb
LOGDIR=		${VARBASE}/log/influxdb

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Disabling phone-home in sample config
SUBST_FILES.fix-cfg=	etc/config.sample.toml
SUBST_SED.fix-cfg=	-e 's/^\# reporting-disabled = false/reporting-disabled = true/'

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
RCD_SCRIPTS=		influxdb

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 etc/influxdb share/doc/influxdb share/examples/influxdb

DOC_FILES+=	LICENSE LICENSE_OF_DEPENDENCIES.md QUERIES.md README.md CHANGELOG.md
BIN_FILES+=	influx influx_inspect influx_stress influx_tsm influxd stress_test_server test_client
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/config.sample.toml ${PKG_SYSCONFDIR}/config.toml

GO_BIN=	${PREFIX}/go19/bin/go

post-extract:
	${MV} ${WRKDIR}/src/github.com/influxdata/${DISTNAME}	\
	  ${WRKDIR}/src/github.com/influxdata/influxdb
#	${CP} files/mmap_solaris.go ${WRKSRC}/pkg/mmap

# TODO: figure out how to properly depend on the extract target
# fetch the additional dependencies that telegraf requires to compile and prepare a tarball containing them for use later.
.PHONY:         _fetch_dependencies
_fetch_dependencies: extract
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} get github.com/sparrc/gdm
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} install github.com/sparrc/gdm
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${WRKDIR}/bin/gdm restore
	cd ${WRKDIR} && ${SETENV} ${PKGSRC_MAKE_ENV} rm -rf src/github.com/influxdata/influxdb
	cd ${WRKDIR} && ${SETENV} ${PKGSRC_MAKE_ENV} find . -type d -name \.git -exec rm -rf {} \;
	cd ${WRKDIR} && ${SETENV} ${PKGSRC_MAKE_ENV} tar czvf ${IFDB_DEPENDENCIES}  src
	cd ${WRKDIR} && ${SETENV} ${PKGSRC_MAKE_ENV} mv ${IFDB_DEPENDENCIES} ${WRKDIR}

# upload the dependency tarball somewhere that others can access.
# this should probably be someplace more "official".
.PHONY: 	_upload_dependencies
_upload_dependencies: 	_fetch_dependencies
	curl -u $$BITBUCKET_USERNAME:$$BITBUCKET_PASSWORD -s -X POST https://api.bitbucket.org/2.0/repositories/$$BITBUCKET_USERNAME/influxdb/downloads -F files=@${WRKDIR}/${IFDB_DEPENDENCIES}

do-build:
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} get -ldflags "-X main.version=${PKGVERSION_NOREV} -X main.commit=${GITHUB_TAG} -X main.buildstamp=pkgsrc" ./...
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} install ./...

do-install:
	cd ${WRKSRC}/man && ${SETENV} ${PKGSRC_MAKE_ENV} ${MAKE_PROGRAM}
.for idir in ${INSTALLATION_DIRS}
	${MKDIR}  ${DESTDIR}${PREFIX}/${idir}
.endfor
	for manpage in ${WRKSRC}/man/*.1 ; do \
		${INSTALL_MAN} $$manpage ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 ; \
	done
.for x in ${BIN_FILES}
	${INSTALL} ${WRKDIR}/bin/${x}	\
	  ${DESTDIR}${PREFIX}/bin/${x}
.endfor
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
	  ${DESTDIR}${PREFIX}/share/doc/influxdb/${x}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/config.sample.toml ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
