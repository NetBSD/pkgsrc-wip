# $NetBSD: Makefile,v 1.5 2014/10/10 12:51:59 fhajny Exp $

# Needs to be rebuilt everytime MySQL version changes
PKGNAME=		${DISTNAME:S/mysql/mysql${MYSQLVER}-sphinxse/}.${SPHINX_VER}

MAINTAINER=		filip@joyent.com
COMMENT=		SphinxSE MySQL storage engine
HOMEPAGE=		http://sphinxsearch.com/
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		automake

MYSQL_VERSIONS_ACCEPTED=51 55 56

.include "../../mk/bsd.prefs.mk"
.include "../../mk/mysql.buildlink3.mk"

.if empty(_MYSQL_VERSION_INSTALLED)
MYSQLVER=		${MYSQL_VERSION_DEFAULT}
.else
MYSQLVER=		${_MYSQL_VERSION_INSTALLED}
.endif

SPHINX=			sphinx-${SPHINX_VER}-release
SPHINX_VER=		2.2.5
DISTFILES=		${DEFAULT_DISTFILES} ${SPHINX}.tar.gz
SITES.${SPHINX}.tar.gz=	http://sphinxsearch.com/files/
IGNOREFILES+=		${SPHINX}.tar.gz
PATCHDIR=		${.CURDIR}/${MYSQL_PKGSRCDIR}/patches
DISTINFO_FILE=		${.CURDIR}/${MYSQL_PKGSRCDIR}/distinfo

PLIST_VARS+=		mysql51 mysql55up

.include "${MYSQL_PKGSRCDIR}/Makefile.common"

.if ${MYSQLVER} == 51
INSTALL_TARGET=		install-data-am
PLIST.mysql51=		yes
DEPENDS+=		mysql-server>=${DISTNAME:S/mysql-//}:${MYSQL_PKGSRCDIR:S/client/server/}
.elif ${MYSQLVER} >= 55
INSTALL_TARGET=		install
PLIST.mysql55up=	yes
DEPENDS+=		mysql-server>=${DISTNAME:S/mysql-//}:${MYSQL_PKGSRCDIR:S/client/server/}
.else
PKG_FAIL_REASON=	"Dynamic plugin loading requires MySQL >= 5.1."
.endif

BUILDLINK_DEPMETHOD.readline=	build

BUILD_DIRS=		storage/sphinx
INSTALLATION_DIRS=	lib/mysql/plugin

post-extract:
	${CP} -R ${WRKDIR}/${SPHINX}/mysqlse ${WRKSRC}/storage/sphinx

post-wrapper:
	cd ${WRKSRC} && ${SH} BUILD/autorun.sh

pre-build:
	${RM} -rf ${BUILDLINK_DIR}/include/mysql

.include "../../mk/bsd.pkg.mk"
