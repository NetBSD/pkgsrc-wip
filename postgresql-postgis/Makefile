# $NetBSD: Makefile,v 1.2 2009/12/16 09:33:59 fhajny Exp $

DISTNAME=		postgis-1.4.0
PKGNAME=		postgresql${PGSQL_VERSION}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases geography
MASTER_SITES=		http://postgis.refractions.net/download/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://postgis.refractions.net/
COMMENT=		Spatial database capabilities for PostgreSQL
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PGSQL_VERSIONS_ACCEPTED=	84

CONFLICTS=		postgis-[0-9]*

# gmake complains about adding + to parent rule
MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex pax perl
USE_LANGUAGES=		c c++

TEST_TARGET=		check

CONFIGURE_ARGS+=	--enable-rpath
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/postgresql/contrib

DOCDIR=		${PREFIX}/share/doc/postgis

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	extras/template_gis/profile \
			extras/template_gis/createdb.postgis.1 \
			extras/template_gis/mktemplate_gis.1 \
			extras/template_gis/postgis_env.sh.in
SUBST_VARS.paths+=	PKG_SYSCONFDIR
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${DOCDIR} ${PKGMANDIR}/man1

# Install is manual because distribution fails if docbook prereqs are not
# satisfied, rather than using the prebuilt versions which are actually
# in the distfile.
do-install:
	cd ${WRKSRC} && ${GMAKE} install DESTDIR=${DESTDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/README.postgis ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.xml ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${BUILD_DIRS:Q}/doc/*.txt ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc/html && pax -rw -pp *.css ${DESTDIR}${DOCDIR}
	${INSTALL_MAN} ${BUILD_DIRS:Q}/doc/man/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

.include "../../geography/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
