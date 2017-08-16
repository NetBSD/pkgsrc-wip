# $NetBSD: Makefile,v 1.2 2012/10/03 18:15:31 asau Exp $

DISTNAME=	nag-h3-${NAGVER}
PKGNAME=	nag-${NAGVER}
CATEGORIES=	www time
MASTER_SITES=	http://ftp.horde.org/pub/nag/ \
	ftp://ftp.horde.org/pub/nag/

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	https://www.horde.org/nag/
COMMENT=	Horde task list manager
LICENSE=	gnu-gpl-v2

DEPENDS+=	horde>=3.2:../../www/horde
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Date-[0-9]*:../../time/pear-Date

USE_TOOLS+= pax

.include "../../mk/bsd.prefs.mk"

DOCDIR=		${PREFIX}/share/doc/nag
EGDIR=		${PREFIX}/share/examples/nag
HORDEDIR=	${PREFIX}/share/horde
NAGDIR=	${HORDEDIR}/nag
NAGVER=	2.3.6
PAXDIRS=	js lib locale po scripts tasklists templates themes

INSTALLATION_DIRS+=${DOCDIR}
INSTALLATION_DIRS+=${EGDIR}
INSTALLATION_DIRS+=${NAGDIR}/config
INSTALLATION_DIRS+=${PAXDIRS}

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin.php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	scripts/import_vtodos.php \
	scripts/upgrades/2004-09-13_add_uid_field.php \
	scripts/upgrades/2006-04-18_add_creator_and_assignee_fields.php \
	scripts/upgrades/convert_datatree_shares_to_sql.php \
	scripts/upgrades/create_missing_add_histories_sql.php

MESSAGE_SUBST+=	NAGDIR=${NAGDIR:Q}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR?=	httpd
USE_PKGINSTALL=	YES

SUBST_CLASSES+=	files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	nag.conf.dist
SUBST_SED.files=	-e "s|@NAGDIR@|${NAGDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

PKG_USERS_VARS+=	APACHE_USER

CONF_FILES=	${EGDIR}/nag.conf ${PKG_SYSCONFDIR}/nag.conf
CONF_FILES_PERMS+=	${NAGDIR}/config/conf.xml.dist \
										${NAGDIR}/config/conf.xml \
										${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${NAGDIR}/config/hooks.php.dist \
										${NAGDIR}/config/hooks.php \
										${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${NAGDIR}/config/menu.php.dist \
										${NAGDIR}/config/menu.php \
										${APACHE_USER} ${ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${NAGDIR}/config/prefs.php.dist \
										${NAGDIR}/config/prefs.php \
										${APACHE_USER} ${ROOT_GROUP} 0440
SPECIAL_PERMS+=	${NAGDIR}/config ${APACHE_USER} ${SHAREGRP} 0750

do-build:
	${CP} ${FILESDIR}/nag.conf.dist ${WRKSRC}/nag.conf.dist
	${CP} ${WRKSRC}/config/conf.xml ${WRKSRC}/config/conf.xml.dist
	${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f

do-install:
	${INSTALL_DATA} ${WRKSRC}/nag.conf.dist ${DESTDIR}${EGDIR}/nag.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELEASE_NOTES ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/UPGRADING ${DESTDIR}${DOCDIR}

. for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpma . ${DESTDIR}${NAGDIR}/${d}
. endfor

	${INSTALL_DATA} ${WRKSRC}/config/*.dist ${DESTDIR}${NAGDIR}/config
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${NAGDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${NAGDIR}
	${FIND} ${DESTDIR}${NAGDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${NAGDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
