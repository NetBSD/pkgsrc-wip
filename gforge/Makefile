# $NetBSD: Makefile,v 1.7 2005/02/04 14:31:17 thomasklausner Exp $

DISTNAME=	gforge-3.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://gforge.org/download.php/44/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.gforge.org/
COMMENT=	Open Source collaborative software development tool

DEPENDS+=	wget>=1.9:../../net/wget
DEPENDS+=	php-jpgraph>=1.12:../../graphics/php-jpgraph
DEPENDS+=	php-pgsql>=4.3:../../databases/php-pgsql
DEPENDS+=	postgresql73-lib>=7.3.1:../../databases/postgresql73-lib

USE_PERL5=	YES
NO_BUILD=	YES

ETCDIR=		${PKG_SYSCONFDIR}/gforge
DATADIR=	${PREFIX}/share/gforge
BACKENDDIR=	${DATADIR}/backends
DOCDIR=		${PREFIX}/share/doc/gforge

SUBST_CLASSES+=		cli
SUBST_STAGE.cli=	post-patch
SUBST_FILES.cli=	`${FIND} ${WRKSRC} -name "*.php"`
SUBST_SED.cli=		-e "s|/usr/bin/php4|${PREFIX}/bin/php|" \
			-e "s|/usr/bin/php|${PREFIX}/bin/php|"

SUBST_CLASSES+=		patches
SUBST_STAGE.patches=	post-patch
SUBST_FILES.patches=	`${FIND} ${WRKSRC} -name "*.patch"`
SUBST_SED.patches=	-e "s|/usr/bin/php4|${PREFIX}/bin/php|" \
			-e "s|/usr/bin/php|${PREFIX}/bin/php|"

SUBST_CLASSES+=		pscripts
SUBST_STAGE.pscripts=	post-patch
SUBST_FILES.pscripts=	`${FIND} ${WRKSRC} -name "*.pl"`
SUBST_FILES.pscipts+=	${WRKSRC}/utils/groupCreator \
			${WRKSRC}/utils/ldap/ldap-clean \
			${WRKSRC}/utils/ldap/ldap-del-user \
			${WRKSRC}/utils/ldap/ldap-dump \
			${WRKSRC}/utils/ldap/ldap-import \
			${WRKSRC}/utils/ldap/ldap-check-replica \
			${WRKSRC}/monitor/systemdaemon
SUBST_SED.pscripts=	-e "s|/usr/bin/perl|${PERL5}|"

SUBST_CLASSES+=		wget
SUBST_STAGE.wget=	post-patch
SUBST_FILES.wget=	${WRKSRC}/utils/mailing_lists_create.pl
SUBST_SED.wget=		-e "s|/usr/bin/wget|${PREFIX}/bin/wget|"

SUBST_CLASSES+=		sdaemon
SUBST_STAGE.sdaemon=	post-patch
SUBST_FILES.sdaemon=	${WRKSRC}/utils/mailing_lists_create.pl
SUBST_SED.sdaemon=	-e "s|/usr/bin:/usr/games:/bin|${PATH}|"

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	post-patch
SUBST_FILES.etcdir=	${WRKSRC}/backend/include.pl \
			${WRKSRC}/utils/include.pl \
			${WRKSRC}/www/include/BaseLanguage.class \
			${WRKSRC}/www/include/pre.php \
			${WRKSRC}/www/include/squal_pre.php
SUBST_SED.etcdir=	-e "s|/etc/gforge|${ETCDIR}|g"

SUBST_CLASSES+=		crontabs
SUBST_STAGE.crontabs=	post-configure
SUBST_FILES.crontabs=	${WRKSRC}/cronjobs/README \
			${WRKSRC}/cronjobs/README.root
SUBST_SED.crontabs=	-e "s|~/alexandria|${BACKENDDIR}|g"

do-install:
	${FIND} ${WRKSRC} -name "*.subst.sav" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/autoconf/local.inc.in \
		${ETCDIR}/local.inc-dist

	${INSTALL_DATA_DIR} ${DATADIR}

.for dir in common www
	${INSTALL_DATA_DIR} ${DATADIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor

.for dir in backend cronjobs monitor utils
	${INSTALL_DATA_DIR} ${BACKENDDIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${BACKENDDIR}/${dir}
.endfor

.for dir in contrib db
	${INSTALL_DATA_DIR} ${DATADIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor

	${INSTALL_DATA_DIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
