# $NetBSD: Makefile,v 1.12 2006/10/12 21:13:41 shattered Exp $

DISTNAME=	gforge-3.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://gforge.org/frs/download.php/44/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://gforge.org/
COMMENT=	Open Source collaborative software development tool

.include "../../lang/php/phpversion.mk"

DEPENDS+=	wget>=1.9:../../net/wget
DEPENDS+=	${PHP_PKG_PREFIX}-jpgraph>=1.12:../../graphics/php-jpgraph
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3:../../databases/php-pgsql

USE_TOOLS+=	perl:run

ETCDIR=		${PKG_SYSCONFDIR}/gforge
DATADIR=	${PREFIX}/share/gforge
BACKENDDIR=	${DATADIR}/backends
DOCDIR=		${PREFIX}/share/doc/gforge

SUBST_CLASSES+=		cli
SUBST_STAGE.cli=	post-patch
SUBST_FILES.cli=	*/*.php */*/*.php */*/*/*.php
SUBST_SED.cli=		-e "1s|/usr/bin/php4|${PREFIX}/bin/php|"
SUBST_SED.cli+=		-e "1s|/usr/.*bin/php|${PREFIX}/bin/php|"

SUBST_CLASSES+=		patches
SUBST_STAGE.patches=	post-patch
SUBST_FILES.patches=	contrib/*.patch
SUBST_SED.patches=	-e "s|/usr/bin/php4|${PREFIX}/bin/php|"
SUBST_SED.patches+=	-e "s|/usr/bin/php|${PREFIX}/bin/php|"

REPLACE_PERL+=		*/*.pl */*/*.pl */*/*/*.pl
REPLACE_PERL+=		monitor/systemdaemon
REPLACE_PERL+=		utils/groupCreator utils/ldap/ldap-*
USE_TOOLS+=		perl:run

SUBST_CLASSES+=		wget
SUBST_STAGE.wget=	post-patch
SUBST_FILES.wget=	utils/mailing_lists_create.pl
SUBST_SED.wget=		-e "s|/usr/bin/wget|${PREFIX}/bin/wget|"

SUBST_CLASSES+=		sdaemon
SUBST_STAGE.sdaemon=	post-patch
SUBST_FILES.sdaemon=	utils/mailing_lists_create.pl
SUBST_SED.sdaemon=	-e "s|/usr/bin:/usr/games:/bin|"${PATH:Q}"|"

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	post-patch
SUBST_FILES.etcdir=	backend/include.pl \
			utils/include.pl \
			www/include/BaseLanguage.class \
			www/include/pre.php \
			www/include/squal_pre.php
SUBST_SED.etcdir=	-e "s|/etc/gforge|${ETCDIR}|g"

SUBST_CLASSES+=		crontabs
SUBST_STAGE.crontabs=	post-configure
SUBST_FILES.crontabs=	cronjobs/README \
			cronjobs/README.root
SUBST_SED.crontabs=	-e "s|~/alexandria|${BACKENDDIR}|g"

REPLACE_BASH+=		utils/decode_images.sh
REPLACE_BASH+=		backend/shell/apache.sh
USE_TOOLS+=		bash:run

do-build:

do-install:
	${FIND} ${WRKSRC} -name "*.subst.sav" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/autoconf/local.inc.in \
		${ETCDIR}/local.inc-dist
	cd ${WRKSRC} && ${PAX} -wr common contrib db www ${DATADIR}
	cd ${WRKSRC} && ${PAX} -wr backend cronjobs monitor utils ${BACKENDDIR}
	cd ${WRKSRC}/docs && ${PAX} -wr * ${DOCDIR}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
