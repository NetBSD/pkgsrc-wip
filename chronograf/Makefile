# $NetBSD$

# TODO give startup scripts more attention
# TODO consider changing default internal paths to reflect ${PREFIX}

GITHUB_PROJECT=		chronograf
PKGVERSION_NOREV=	1.7.7
DISTNAME=		chronograf-1.7.7
GITHUB_TAG=		${PKGVERSION_NOREV}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=influxdata/}
MAINTAINER=		william@welliver.org
HOMEPAGE=		https://www.influxdata.com/
COMMENT=		Monitoring and visualization UI for the TICK stack
LICENSE=		gnu-agpl-v3

# despite being the default value, this explicit declaration is required for things
# to build properly.
EXTRACT_SUFX=	.tar.gz

CHRONOGRAF_DISTNAME=		${DISTNAME}${EXTRACT_SUFX}
CHRONOGRAF_DEPENDENCIES_DIR=	chronograf-dependencies-${PKGVERSION_NOREV}
CHRONOGRAF_DEPENDENCIES=	${CHRONOGRAF_DEPENDENCIES_DIR}${EXTRACT_SUFX}

DISTFILES=			${CHRONOGRAF_DISTNAME}

.if !defined(BOOTSTRAP)
DISTFILES+=	${CHRONOGRAF_DEPENDENCIES}
SITES.${CHRONOGRAF_DEPENDENCIES}= https://bitbucket.org/hww3/influxdb/downloads/
.endif

EXTRACT_DIR.${CHRONOGRAF_DISTNAME}=	${WRKDIR}/src/github.com/influxdata
WRKSRC=		${WRKDIR}/src/github.com/influxdata/chronograf
USE_TOOLS+=	gmake curl
USE_LANGUAGES+=	c c++

BUILD_DEPENDS+=		go110-1.10.*:../../lang/go110
BUILD_DEPENDS+=		py27-gyp-[0-9]*:../../devel/gyp
BUILD_DEPENDS+=		python27-2.7.*:../../lang/python27
BUILD_DEPENDS+=		npm-6.*.*:../../lang/npm
BUILD_DEPENDS+=		yarn-1.7.*:../../devel/yarn

# go language executables don't have SSP support
CHECK_SSP_SKIP=	bin/*

PKGSRC_MAKE_ENV+=	GOPATH=${WRKDIR}
PKGSRC_MAKE_ENV+=	GO_BIN=${GO_BIN}
PKGSRC_MAKE_ENV+=	PYTHON=${PREFIX}/bin/python2.7
PKGSRC_MAKE_ENV+=	YARN_DISABLE_SELF_UPDATE_CHECK="true"

PKG_SYSCONFSUBDIR=	chronograf

RESOURCEDIR=	${PREFIX}/share/chronograf
DATADIR=	${VARBASE}/lib/chronograf
LOGDIR=		${VARBASE}/log/chronograf

BUILD_DEFS+=		CHRONOGRAF_USER CHRONOGRAF_GROUP VARBASE
FILES_SUBST+=		CHRONOGRAF_USER=${CHRONOGRAF_USER:Q}
FILES_SUBST+=		CHRONOGRAF_GROUP=${CHRONOGRAF_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}
FILES_SUBST+=		RESOURCEDIR=${RESOURCEDIR:Q}

CHRONOGRAF_USER?=	chronograf
CHRONOGRAF_GROUP?=	chronograf
OWN_DIRS_PERMS+=	${DATADIR} ${CHRONOGRAF_USER} ${CHRONOGRAF_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${CHRONOGRAF_USER} ${CHRONOGRAF_GROUP} 0700
PKG_USERS_VARS+=	CHRONOGRAF_USER
PKG_GROUPS_VARS+=	CHRONOGRAF_GROUP
PKG_GROUPS=		${CHRONOGRAF_GROUP}
PKG_USERS=		${CHRONOGRAF_USER}:${CHRONOGRAF_GROUP}
RCD_SCRIPTS=		chronograf

INSTALLATION_DIRS+=	bin etc/chronograf share/doc/chronograf share/examples/chronograf share/examples/chronograf/logrotate.d share/chronograf/canned share/chronograf/protoboards

DOC_FILES+=	LICENSE LICENSE_OF_DEPENDENCIES.md README.md CHANGELOG.md platform_migrate.md agpl-3.0.md
BIN_FILES+=	chronograf chronoctl

GO_BIN=		${PREFIX}/go110/bin/go
CPPFLAGS+=	-I${PREFIX}/include/node
CFLAGS+=	-I${PREFIX}/include/node

post-extract:
	${MV} ${WRKDIR}/src/github.com/influxdata/${DISTNAME}	\
	  ${WRKDIR}/src/github.com/influxdata/chronograf
.if !defined(BOOTSTRAP)
	${MV} ${WRKDIR}/vendor_js ${WRKSRC}/ui
.endif

# it doesn't seem like there's a way to get yarn to fetch but not build dependencies.
# also, need to figure out a way to get the target dependency to work properly on this make target.
.PHONY:	_fetch_dependencies
_fetch_dependencies: extract
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} ${TOUCH} .godep
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} ${MKDIR} ${WRKSRC}/vendor_js
	cd ${WRKSRC}/ui && ${ECHO} yarn-offline-mirror \"./vendor_js\" > .yarnrc
	cd ${WRKSRC}/ui && ${SETENV} ${PKGSRC_MAKE_ENV} yarn --no-progress --no-emoji --offline --verbose
	cd ${WRKSRC}/ui && ${SETENV} ${PKGSRC_MAKE_ENV} tar czvf ${CHRONOGRAF_DEPENDENCIES}  vendor_js
	cd ${WRKSRC}/ui && ${SETENV} ${PKGSRC_MAKE_ENV} mv ${CHRONOGRAF_DEPENDENCIES} /data/pkgsrc/wip/chronograf

# upload the dependency tarball somewhere that others can access.
# this should probably be someplace more "official".
.PHONY:         _upload_dependencies
_upload_dependencies:   _fetch_dependencies
	curl -u $$BITBUCKET_USERNAME:$$BITBUCKET_PASSWORD -s -X POST https://api.bitbucket.org/2.0/repositories/$$BITBUCKET_USERNAME/influxdb/downloads -F files=@${CHRONOGRAF_DEPENDENCIES}

do-build:
	touch ${WRKSRC}/.jsdep
	touch ${WRKSRC}/.godep
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} ${GMAKE} .godep
	cd ${WRKSRC}/vendor/github.com/kevinburke/go-bindata && ${SETENV} ${PKGSRC_MAKE_ENV} ${GO_BIN} install ./...
	cd ${WRKSRC}/ui && ${ECHO} yarn-offline-mirror \"./vendor_js\" > .yarnrc
	cd ${WRKSRC}/ui && ${SETENV} ${PKGSRC_MAKE_ENV} CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" yarn --no-progress --no-emoji --offline
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} PATH=$$PATH:${WRKDIR}/bin ${GMAKE} build
#	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} get -ldflags "-X main.version=${PKGVERSION_NOREV} -X main.commit=${GITHUB_TAG} -X main.buildstamp=pkgsrc" ./...
#	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}  ${GO_BIN} install ./...

do-install:
.for idir in ${INSTALLATION_DIRS}
	${MKDIR}  ${DESTDIR}${PREFIX}/${idir}
.endfor
.for x in ${BIN_FILES}
	${INSTALL} ${WRKSRC}/${x} \
	  ${DESTDIR}${PREFIX}/bin/${x}
.endfor
.for x in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${x} \
	  ${DESTDIR}${PREFIX}/share/doc/chronograf/${x}
.endfor

	for x in ${WRKSRC}/canned/*.json ; do \
	  ${INSTALL_DATA} $$x ${DESTDIR}${PREFIX}/share/${PKGBASE}/canned/ ;\
	done
	for x in ${WRKSRC}/protoboards/*.json ; do \
	  ${INSTALL_DATA} $$x ${DESTDIR}${PREFIX}/share/${PKGBASE}/protoboards/ ;\
	done
.include "../../lang/nodejs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
