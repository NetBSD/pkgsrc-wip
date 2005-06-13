# $NetBSD: Makefile,v 1.4 2005/06/13 00:09:12 kristerw Exp $
#

VERSION=		1.0.0-rc2
PKGNAME=		postgresql80-postgis-${VERSION}
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
COMMON_FILESDIR=	${.CURDIR}/../../databases/postgresql80/files
PATCHDIR=		${.CURDIR}/../../databases/postgresql80/patches

.include "../../databases/postgresql80/Makefile.common"

MASTER_SITES+=  	${PGSQL_SITES:=source/v${DIST_VERS}/}
MASTER_SITES+=  	http://postgis.refractions.net/

USE_PERL5=		YES

PGSQL_VERSION_REQD=	80

# Add postgis to the postgresql distfile
DISTFILES+=      	postgis-${VERSION}.tar.gz ${DISTNAME}${EXTRACT_SUFX}

# Only build the postgis contribted source
BUILD_DIRS=		${WRKSRC}/contrib/postgis-${VERSION}

BINDIR=			${PREFIX}/bin
LIBDIR=			${PREFIX}/lib/postgresql
DOCDIR=			${PREFIX}/share/doc/postgis
EXAMPLEDIR=		${PREFIX}/share/examples/postgis
HTMLDIR=		${PREFIX}/share/doc/html/postgis
SQLDIR=			${PREFIX}/share/postgresql

MAKE_ENV+=		PROJ_DIR=${PREFIX}
MAKE_ENV+=		GEOS_DIR=${PREFIX}

# install postgis source within contrib directory
pre-build:
	${MV} ${WRKDIR}/postgis-1.0.0-rc2 ${WRKSRC}/contrib

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EXAMPLEDIR} ${HTMLDIR} ${SQLDIR}
	cd ${BUILD_DIRS} && ${GMAKE} install
	${CP} -r ${BUILD_DIRS}/examples/* ${EXAMPLEDIR}
	${INSTALL_DATA} ${BUILD_DIRS}/README.postgis ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS}/doc/postgis.xml ${DOCDIR}
	${CP} -r ${BUILD_DIRS}/doc/html/* ${HTMLDIR}

.include "../../wip/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
