# $NetBSD: Makefile,v 1.8 2006/03/23 04:12:22 mchittur Exp $
#
VERSION=		1.1.1
PKGNAME=		postgresql74-postgis-${VERSION}
CATEGORIES=		databases geography

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL

CONFLICTS=		postgis-[0-9]*

# XXX - Override these so they work correctly with Makefile.common.
#       The last two don't really need changing, except that Makefile.common
#       uses .. rather than ../../databases; the former will not work from
#	arbitrary directories.
DISTINFO_FILE=		${.CURDIR}/distinfo
COMMON_FILESDIR=	${.CURDIR}/../../databases/postgresql74/files
PATCHDIR=		${.CURDIR}/../../databases/postgresql74/patches

.include "../../databases/postgresql74/Makefile.common"

MASTER_SITES+=  	${PGSQL_SITES:=source/v${DIST_VERS}/}
MASTER_SITES+=  	http://postgis.refractions.net/download/

PGSQL_VERSION_REQD=	74

# Add postgis to the postgresql distfile
DISTFILES+=      	postgis-${VERSION}.tar.gz ${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=		perl
USE_TOOLS+=		gmake

# Only build the postgis contribted source
BUILD_DIRS=		${WRKSRC}/contrib/postgis-${VERSION}

EXAMPLEDIR=		${PREFIX}/share/examples/postgis
SCRIPTDIR=		${PREFIX}/share/postgis

MAKE_ENV+=		PROJ_DIR=${PREFIX:Q}
MAKE_ENV+=		GEOS_DIR=${PREFIX:Q}

MAKEFILE=		GNUmakefile

# configures postgis source within contrib directory
post-configure:
	${MV} ${WRKDIR}/postgis-${VERSION} ${WRKSRC}/contrib
	cd ${WRKSRC}/contrib/postgis-${VERSION}/ && ${CONFIGURE_SCRIPT} --enable-autoconf --with-geos=${PREFIX:Q}/bin/geos-config

pre-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR} ${SCRIPTDIR}

post-install:
	${CP} -r ${BUILD_DIRS}/regress/* ${EXAMPLEDIR}
	${CP} -r ${BUILD_DIRS}/utils/*   ${SCRIPTDIR}

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
