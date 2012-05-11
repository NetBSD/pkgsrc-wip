# $NetBSD: Makefile,v 1.2 2012/05/11 09:39:41 fhajny Exp $

PKGNAME=		${DISTNAME:S/mysql-/mysql-sphinxse-/}.${SPHINX_VER}

MAINTAINER=		filip@joyent.com
COMMENT=		SphinxSE MySQL storage engine
HOMEPAGE=		http://sphinxsearch.com/
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		automake

.include "../../mk/bsd.prefs.mk"

MYSQL_VERSION=		${MYSQL_VERSION_DEFAULT}

SPHINX=			sphinx-${SPHINX_VER}-release
SPHINX_VER=		2.0.3
DISTFILES=		${DEFAULT_DISTFILES} ${SPHINX}.tar.gz
SITES.${SPHINX}.tar.gz=	http://sphinxsearch.com/files/
IGNOREFILES+=		${SPHINX}.tar.gz

PLIST_VARS+=		mysql51 mysql55

.if ${MYSQL_VERSION} == 51
INSTALL_TARGET=		install-data-am
PLIST.mysql51=		yes
.include "../../databases/mysql51-client/Makefile.common"
PATCHDIR=		${.CURDIR}/../../databases/mysql51-client/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/mysql51-client/distinfo
DEPENDS+=		mysql-server-5.1.*:../../databases/mysql51-server
.elif ${MYSQL_VERSION} == 55
INSTALL_TARGET=		install
PLIST.mysql55=		yes
.include "../../databases/mysql55-client/Makefile.common"
PATCHDIR=		${.CURDIR}/../../databases/mysql55-client/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/mysql55-client/distinfo
DEPENDS+=		mysql-server-5.5.*:../../databases/mysql55-server
.else
PKG_FAIL_REASON=	"Dynamic plugin loading requires MySQL >= 5.1."
.endif

BUILDLINK_DEPMETHOD.readline=	build

BUILD_DIRS=		storage/sphinx
INSTALLATION_DIRS=	lib/mysql/plugin

post-extract:
	${CP} -R ${WRKDIR}/${SPHINX}/mysqlse ${WRKSRC}/storage/sphinx

post-patch:
	cd ${WRKSRC} && ${SH} BUILD/autorun.sh

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
