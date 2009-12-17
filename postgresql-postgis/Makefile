# $NetBSD: Makefile,v 1.5 2009/12/17 10:01:58 fhajny Exp $

DISTNAME=		postgis-1.4.1rc2
PKGNAME=		postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases geography
MASTER_SITES=		http://postgis.refractions.net/download/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# See TODO
PGSQL_VERSIONS_ACCEPTED=	84

DEPENDS+=		postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

CONFLICTS=		postgis-[0-9]*

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake lex pax perl
USE_LANGUAGES=		c c++

TEST_TARGET=		check

CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

DOCDIR=			${PREFIX}/share/doc/postgis

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	extras/template_gis/profile \
			extras/template_gis/createdb.postgis.1 \
			extras/template_gis/mktemplate_gis.1 \
			extras/template_gis/postgis_env.sh.in
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/images ${PKGMANDIR}/man1

# Docs install is manual because distribution fails if docbook prereqs are not
# satisfied, rather than using the prebuilt versions which are actually
# in the distfile.
post-install:
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/postgis.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/style.css ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/html/images/* ${DESTDIR}${DOCDIR}/images
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/postgis_comments.sql ${DESTDIR}${PREFIX}/share/postgresql/contrib
	${INSTALL_MAN} ${BUILD_DIRS:Q}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
