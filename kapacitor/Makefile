# $NetBSD$

GITHUB_PROJECT=		kapacitor
PKGVERSION_NOREV=	1.5.2
DISTNAME=		kapacitor-1.5.2
GITHUB_TAG=		v${PKGVERSION_NOREV}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=influxdata/}
MAINTAINER=		william@welliver.org
HOMEPAGE=		https://www.influxdata.com/
COMMENT=		Framework for processing, monitoring, and alerting on time series data
LICENSE=		mit

# despite being the default value, this explicit declaration is required for things
# to build properly.
EXTRACT_SUFX=	.tar.gz

KAPACITOR_DISTNAME=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES=		${KAPACITOR_DISTNAME}

EXTRACT_DIR.${KAPACITOR_DISTNAME}=	${WRKDIR}/src/github.com/influxdata
WRKSRC=		${WRKDIR}/src/github.com/influxdata/kapacitor
USE_TOOLS+=	gmake

BUILD_DEPENDS+=			go110-1.10.*:../../lang/go110

# go language executables don't have SSP support
CHECK_SSP_SKIP=	bin/*

PKGSRC_MAKE_ENV+=		GOPATH=${WRKDIR}

PKG_SYSCONFSUBDIR=	kapacitor

REPLACE.kapacitor.old=		/etc/kapacitor
REPLACE.kapacitor.new=		${PKG_SYSCONFDIR}
REPLACE_FILES.kapacitor=	share/examples/kapacitor/kapacitor.conf

DATADIR=	${VARBASE}/lib/kapacitor
LOGDIR=		${VARBASE}/log/kapacitor

BUILD_DEFS+=		KAPACITOR_USER KAPACITOR_GROUP VARBASE
FILES_SUBST+=		KAPACITOR_USER=${KAPACITOR_USER:Q}
FILES_SUBST+=		KAPACITOR_GROUP=${KAPACITOR_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}
FILES_SUBST+=		LOGDIR=${LOGDIR:Q}

KAPACITOR_USER?=	kapacitor
KAPACITOR_GROUP?=	kapacitor
OWN_DIRS_PERMS+=	${DATADIR} ${KAPACITOR_USER} ${KAPACITOR_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${KAPACITOR_USER} ${KAPACITOR_GROUP} 0700
PKG_USERS_VARS+=	KAPACITOR_USER
PKG_GROUPS_VARS+=	KAPACITOR_GROUP
PKG_GROUPS=		${KAPACITOR_GROUP}
PKG_USERS=		${KAPACITOR_USER}:${KAPACITOR_GROUP}
RCD_SCRIPTS=		kapacitor

INSTALLATION_DIRS+=	bin etc/kapacitor share/doc/kapacitor share/kapacitor/telegraf share/examples/kapacitor/logrotate.d

DOC_FILES+=	LICENSE LICENSE_OF_DEPENDENCIES.md DESIGN.md README.md CHANGELOG.md
BIN_FILES+=	kapacitor kapacitord
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/kapacitor.conf ${PKG_SYSCONFDIR}/kapacitor.conf
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/logrotate.d/kapacitor ${PKG_SYSCONFDIR}/../logrotate.d/kapacitor

GO_BIN=	${PREFIX}/go110/bin/go

post-extract:
	${MV} ${WRKDIR}/src/github.com/influxdata/${DISTNAME}	\
	  ${WRKDIR}/src/github.com/influxdata/kapacitor

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
	  ${DESTDIR}${PREFIX}/share/doc/kapacitor/${x}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/kapacitor/kapacitor.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/etc/logrotate.d/kapacitor ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/logrotate.d/kapacitor

.include "../../mk/bsd.pkg.mk"
