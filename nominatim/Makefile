# $NetBSD$

DISTNAME=	Nominatim-3.2.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	geography
MASTER_SITES=	http://www.nominatim.org/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://www.nominatim.org/
COMMENT=	Open Source search based on OpenStreetMap data
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash gmake pax
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/php/phpversion.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-pear-DB-[0-9]*:../../databases/pear-DB
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql*-[0-9]*:../../databases/php-pgsql
DEPENDS+=	postgresql${PGSQL_VERSION}-contrib-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-contrib
DEPENDS+=	postgresql${PGSQL_VERSION}-postgis-[0-9]*:../../databases/postgresql-postgis2

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}
CMAKE_FLAGS+=	-DPHP_BIN=${PREFIX}/bin/php

REPLACE_BASH+=		utils/import_wikipedia.sh
REPLACE_PYTHON+=	utils/*.py
REPLACE_INTERPRETER+=	php
REPLACE.php.old=	[^[:space:]]*[pP][hH][pP][^[:space:]]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	utils/*.php

NDIR=		${PREFIX}/share/nominatim
MODDIR=		${PREFIX}/lib/nominatim

INSTALLATION_DIRS=	bin ${MODDIR}
INSTALLATION_DIRS+=	${NDIR}/data
INSTALLATION_DIRS+=	${NDIR}/lib
INSTALLATION_DIRS+=	${NDIR}/nominatim
INSTALLATION_DIRS+=	${NDIR}/osm2pgsql
INSTALLATION_DIRS+=	${NDIR}/settings
INSTALLATION_DIRS+=	${NDIR}/sql
INSTALLATION_DIRS+=	${NDIR}/utils
INSTALLATION_DIRS+=	${NDIR}/website

SUBST_CLASSES+=		paths
SUBST_FILES.paths+=	${WRKSRC}/settings/defaults.php
SUBST_SED.paths+=	-e "s|@CMAKE_SOURCE_DIR@|${NDIR}|g"
SUBST_SED.paths+=	-e "s|@CMAKE_BINARY_DIR@|${NDIR}|g"
SUBST_SED.paths+=	-e "s|CONST_InstallPath.'/module'|'${MODDIR}'|g"
SUBST_STAGE.paths=	post-configure

.include "../../lang/python/application.mk"

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

do-install:
.for d in data lib sql utils website
	cd ${WRKSRC}/${d} && pax -rw . ${DESTDIR}${NDIR}/${d}
.endfor
	${INSTALL_LIB} ${WRKDIR}/build/module/nominatim.so ${DESTDIR}${MODDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/build/nominatim/nominatim ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKDIR}/build/osm2pgsql/osm2pgsql ${DESTDIR}${NDIR}/osm2pgsql/
	ln -f -s ${DESTDIR}${PREFIX}/bin/nominatim ${DESTDIR}${NDIR}/nominatim/
	${INSTALL_DATA} ${WRKDIR}/build/settings/*.php ${DESTDIR}${NDIR}/settings/

.include "../../geography/proj/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
