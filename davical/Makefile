# $NetBSD: Makefile,v 1.2 2010/05/17 00:46:30 jym-netbsd Exp $
#

DISTNAME=	davical-${DAVICAL_VERSION}
DAVICAL_VERSION=0.9.8.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rscds/}

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://www.davical.org/
COMMENT=	Simple CalDAV server using a PostgreSQL backend

LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DAVICALDIR=	${PREFIX}/share/davical
EGDIR=		${PREFIX}/share/examples/davical
DOCDIR=		${PREFIX}/share/doc/davical

BUILD_DEFS=	APACHE_USER APACHE_GROUP

DAVICAL_USER?=	${APACHE_USER}
DAVICAL_GROUP?=	${APACHE_GROUP}

USE_TOOLS=	pax perl:build

PAXDIRS=	htdocs inc dba po scripts

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}/config

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.1:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=${PHP_BASE_VERS}:../../databases/php-pdo_pgsql
DEPENDS+=	php-libawl>=0.42:../../wip/php-libawl
DEPENDS+=	p5-DBD-postgresql>=2.16.1:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-Class-DBI-Pg>=0.09:../../databases/p5-Class-DBI-Pg
DEPENDS+=	p5-YAML-LibYAML>=0.32:../../textproc/p5-YAML-LibYAML
DEPENDS+=	pwgen>=2.06:../../sysutils/pwgen
DEPENDS+=	postgresql${PGSQL_VERSION}-client-[0-9]*:../../databases/postgresql${PGSQL_VERSION}-client

PKG_SYSCONFSUBDIR=	davical
PKG_SYSCONFDIR_PERMS=	${DAVICAL_USER} ${DAVICAL_GROUP} 0700

MESSAGE_SUBST+=		DAVICALDIR=${DAVICALDIR:Q} DOCDIR=${DOCDIR:Q}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

CONF_FILES=		${EGDIR}/davical.conf	\
			${PKG_SYSCONFDIR}/davical.conf

CONF_FILES_PERMS+=	${EGDIR}/config/example-config.php	\
			${PKG_SYSCONFDIR}/config.php		\
			${DAVICAL_USER} ${DAVICAL_GROUP} 0640

CONF_FILES_PERMS+=	${EGDIR}/config/example-administration.yml	\
			${PKG_SYSCONFDIR}/administration.yml		\
			${DAVICAL_USER} ${DAVICAL_GROUP} 0640

REPLACE_INTERPRETER+=	perl
REPLACE.perl.old=	.*/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	scripts/po/extract.pl

SUBST_CLASSES+=		conf-path
SUBST_STAGE.conf-path=	post-patch
SUBST_FILES.conf-path=	inc/always.php dba/update-davical-database
SUBST_SED.conf-path+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf-path=Fixing configuration path.

# See ../../devel/php-libawl for the path to the AWL include directory
SUBST_CLASSES+=		inc-path
SUBST_STAGE.inc-path=	post-patch
SUBST_FILES.inc-path=	inc/always.php scripts/po/rebuild-translations.sh
SUBST_SED.inc-path+=	-e "s|@LIBAWLDIR@|${PREFIX}/${LIBAWLDIR}|g"
SUBST_MESSAGE.inc-path=	Fixing AWL include path.

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	davical.conf
SUBST_SED.files+=	-e "s|@DAVICALDIR@|${DAVICALDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

post-extract:
	${CP} ${FILESDIR}/davical.conf ${WRKSRC}/davical.conf

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f

do-install:
	cd ${WRKSRC};							\
	for f in COPYING CREDITS ChangeLog				\
	    INSTALL README TODO VERSION; do				\
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${DOCDIR};	\
	done

	${INSTALL_DATA} ${WRKSRC}/davical.conf	\
		${DESTDIR}${EGDIR}/davical.conf

	cd ${WRKSRC}/docs && pax -rwpam . ${DESTDIR}${DOCDIR}

.	for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${DAVICALDIR}/${d}
.	endfor

.	for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${DAVICALDIR}/${d}
.	endfor

	cd ${WRKSRC}/config && for f in *; do				\
		${INSTALL_DATA} $$f ${DESTDIR}${EGDIR}/config/$$f;	\
	done

.include "../../mk/pgsql.buildlink3.mk"
.include "../../wip/php-libawl/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
