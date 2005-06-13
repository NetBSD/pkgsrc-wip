# $NetBSD: Makefile,v 1.2 2005/06/13 00:09:11 kristerw Exp $
#

VERSION=		0.8.2
PKGNAME=		postgis-${VERSION}
CATEGORIES=		databases geography
MASTER_SITES+=  	${PGSQL_SITES:=source/v${DIST_VERS}/}
MASTER_SITES+=  	http://postgis.refractions.net/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL

# XXX - Override these so they work correctly with Makefile.common.
#       The last two don't really need changing, except that Makefile.common
#       uses .. rather than ../../databases; the former will not work from
#	arbitrary directories.
DISTINFO_FILE=		${.CURDIR}/distinfo
COMMON_FILESDIR=	${.CURDIR}/../../databases/postgresql74/files
PATCHDIR=		${.CURDIR}/../../databases/postgresql74/patches

.include "../../databases/postgresql74/Makefile.common"

USE_PERL5=		YES

# Add postgis to the postgresql distfile
DISTFILES+=      	postgis-${VERSION}.tar.gz ${DISTNAME}${EXTRACT_SUFX}

# Only build the postgis contribted source
BUILD_DIRS=		${WRKSRC}/contrib/postgis-${VERSION}

BINDIR=			${PREFIX}/bin
LIBDIR=			${PREFIX}/lib/postgresql
DOCDIR=			${PREFIX}/share//doc/postgis
EXAMPLEDIR=		${PREFIX}/share/examples/postgis
HTMLDIR=		${PREFIX}/share/doc/html/postgis
SQLDIR=			${PREFIX}/share/postgresql

MAKE_ENV+=		PROJ_DIR=${PREFIX}
MAKE_ENV+=		GEOS_DIR=${PREFIX}

# install postgis source within contrib directory
pre-build:
	${MV} ${WRKDIR}/${PKGNAME} ${WRKSRC}/contrib

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EXAMPLEDIR} ${HTMLDIR} ${SQLDIR}
.for f in libpostgis.a libpostgis.so.0.8
	${INSTALL_DATA} ${BUILD_DIRS}/$f ${LIBDIR}/$f
.endfor
	${RM} -f ${LIBDIR}/libpostgis.so.0
	${RM} -f ${LIBDIR}/libpostgis.so
	${LN} -s libpostgis.so.0.8 ${LIBDIR}/libpostgis.so.0
	${LN} -s libpostgis.so.0.8 ${LIBDIR}/libpostgis.so
.for f in postgis.sql postgis_undef.sql spatial_ref_sys.sql
	${INSTALL_DATA} ${BUILD_DIRS}/$f ${SQLDIR}/$f
.endfor
.for f in pgsql2shp shp2pgsql
	${INSTALL_PROGRAM} ${BUILD_DIRS}/loader/$f ${PREFIX}/bin/$f
.endfor
	${CP} -r ${BUILD_DIRS}/examples/* ${EXAMPLEDIR}
	${INSTALL_DATA} ${BUILD_DIRS}/README.postgis ${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS}/doc/postgis.xml ${DOCDIR}
	${CP} -r ${BUILD_DIRS}/doc/html/* ${HTMLDIR}

.include "../../wip/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
