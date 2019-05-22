# $NetBSD$

GITHUB_PROJECT=		telegraf
PKGVERSION_NOREV=	1.9.2
DISTNAME=		telegraf-1.9.2
GITHUB_TAG=		${PKGVERSION_NOREV}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=influxdata/}
MAINTAINER=		william@welliver.org
HOMEPAGE=		https://www.influxdata.com/
COMMENT=		Plugin-driven server agent for collecting & reporting metrics
LICENSE=		mit

# despite being the default value, this explicit declaration is required for things
# to build properly.
EXTRACT_SUFX=			.tar.gz
TELEGRAF_DEPENDENCIES_DIR=	telegraf-dependencies-${PKGVERSION_NOREV}
TELEGRAF_DEPENDENCIES=		${TELEGRAF_DEPENDENCIES_DIR}${EXTRACT_SUFX}
TELEGRAF_DISTNAME=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES=			${TELEGRAF_DISTNAME}

.if !defined(BOOTSTRAP)
DISTFILES+=	${TELEGRAF_DEPENDENCIES}
SITES.${TELEGRAF_DEPENDENCIES}= https://bitbucket.org/hww3/influxdb/downloads/
.endif

USE_TOOLS+=	gmake curl

BUILD_DEPENDS+=			go110-1.10.*:../../lang/go110

# go language executables don't have SSP support
CHECK_SSP_SKIP=	bin/*

PKGSRC_MAKE_ENV+=		GOPATH=${WRKDIR}

PKG_SYSCONFSUBDIR=	telegraf

DATADIR=	${VARBASE}/lib/telegraf
LOGDIR=		${VARBASE}/log/telegraf

BUILD_DEFS+=		TELEGRAF_USER TELEGRAF_GROUP VARBASE
FILES_SUBST+=		TELEGRAF_USER=${TELEGRAF_USER:Q}
FILES_SUBST+=		TELEGRAF_GROUP=${TELEGRAF_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

TELEGRAF_USER?=		telegraf
TELEGRAF_GROUP?=	telegraf
OWN_DIRS_PERMS+=	${DATADIR} ${TELEGRAF_USER} ${TELEGRAF_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${TELEGRAF_USER} ${TELEGRAF_GROUP} 0700
PKG_USERS_VARS+=	TELEGRAF_USER
PKG_GROUPS_VARS+=	TELEGRAF_GROUP
PKG_GROUPS=		${TELEGRAF_GROUP}
PKG_USERS=		${TELEGRAF_USER}:${TELEGRAF_GROUP}
RCD_SCRIPTS=		telegraf

INSTALLATION_DIRS+=	bin etc/telegraf etc/logrotate.d share/doc/telegraf share/examples/telegraf share/examples/telegraf/logrotate.d

DOC_FILES+=	LICENSE README.md CHANGELOG.md
BIN_FILES+=	telegraf
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/telegraf.conf ${PKG_SYSCONFDIR}/telegraf.conf
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/logrotate.d/telegraf ${PKG_SYSCONFDIR}/../logrotate.d/telegraf

WRKSRC=	${WRKDIR}/src/github.com/influxdata/telegraf
GO_BIN=	${PREFIX}/go110/bin/go

# TODO: figure out how to properly depend on the extract target
# fetch the additional dependencies that telegraf requires to compile and prepare a tarball containing them for use later.
.PHONY: 	_fetch_dependencies
_fetch_dependencies: extract
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} get -u github.com/golang/dep/cmd/dep
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} install github.com/golang/dep/cmd/dep
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${WRKDIR}/bin/dep ensure -vendor-only
	cd ${WRKSRC}/vendor && ${SETENV} ${PKGSRC_MAKE_ENV} find . -type d -name \.git -exec rm -rf {} \;
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} tar czvf ${TELEGRAF_DEPENDENCIES}  vendor
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} mv ${TELEGRAF_DEPENDENCIES} /data/pkgsrc/wip/telegraf

# upload the dependency tarball somewhere that others can access.
# this should probably be someplace more "official".
.PHONY: 	_upload_dependencies
_upload_dependencies: 	_fetch_dependencies
	curl -u $$BITBUCKET_USERNAME:$$BITBUCKET_PASSWORD -s -X POST https://api.bitbucket.org/2.0/repositories/$$BITBUCKET_USERNAME/influxdb/downloads -F files=@${TELEGRAF_DEPENDENCIES}

# we should probably guard this code to make sure it's not done twice.
pre-extract:
	${MKDIR} ${WRKDIR}/src/github.com/influxdata/

post-extract:
	ls -l ${WRKDIR}
	${MV} ${WRKDIR}/${DISTNAME} ${WRKSRC}
.if !defined(BOOTSTRAP)
	${MV} ${WRKDIR}/vendor ${WRKSRC}/
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} get -ldflags "-X main.version=${PKGVERSION_NOREV} -X main.commit=${GITHUB_TAG} -X main.buildstamp=pkgsrc" ./...
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} install ./...

do-install:
.for idir in ${INSTALLATION_DIRS}
	${MKDIR}  ${DESTDIR}${PREFIX}/${idir}
.endfor
.for x in ${BIN_FILES}
	${INSTALL} ${WRKDIR}/bin/${x}	\
	  ${DESTDIR}${PREFIX}/bin/${x}
.endfor
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
	  ${DESTDIR}${PREFIX}/share/doc/telegraf/${x}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/telegraf.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/etc/logrotate.d/telegraf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/logrotate.d/telegraf

#.include "../../lang/go19/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
