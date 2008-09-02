# $NetBSD: Makefile,v 1.1.1.1 2008/09/02 16:41:08 pettai Exp $
#

DISTNAME=		gallery-2.2.5-full
PKGNAME=		gallery2-2.2.5
CATEGORIES=		www graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gallery/}

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://gallery.sourceforge.net/
COMMENT=		Web-based photo gallery written in PHP
#LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
NO_BUILD=		yes
WRKSRC=			${WRKDIR}/gallery2

DEPENDS+=		${PHP_PKG_PREFIX}-gettext>=5.0.4:../../devel/php-gettext
DEPENDS+=		${PHP_PKG_PREFIX}-{,mysql,pgsql}:../../databases/php-mysql
DEPENDS+=		{mysql-,pgsql-}server-[0-9]*:../../databases/mysql5-server

PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_USERS_VARS+=	APACHE_USER
BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/gallery2
G2DIR=			${PREFIX}/share/gallery2
DATADIR=		${VARBASE}/db/gallery2
G2DATA=			${DATADIR}/g2data

MESSAGE_SUBST+=		G2DIR=${G2DIR}
MESSAGE_SUBST+=		G2DATA=${G2DATA}
FILES_SUBST+=		G2DIR=${G2DIR}

OWN_DIRS=		${G2DIR} ${DATADIR}
OWN_DIRS_PERMS+=	${G2DATA} ${APACHE_USER} ${APACHE_GROUP} 755

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/gallery2.conf
SUBST_FILES.paths+=	${WRKSRC}/config.php
SUBST_SED.paths+=	-e 's,@G2DIR@,${G2DIR},g'
SUBST_SED.paths+=	-e 's,@G2DATA@,${G2DATA},g'
SUBST_STAGE.paths=	post-patch

INSTALLATION_DIRS=	share/examples/gallery2
INSTALLATION_DIRS+=	share/gallery2
INSTALLATION_DIRS+=	${G2DATA}

post-extract:
	${CP} ${FILESDIR}/gallery2.conf ${WRKDIR}/
	${CP} ${FILESDIR}/config.php ${WRKSRC}/config.php

do-install:
	${INSTALL_DATA} ${WRKDIR}/gallery2.conf ${EGDIR}/gallery2.conf
	${CP} -R ${WRKSRC}/* ${G2DIR}
	${CHMOD} 666 ${G2DIR}/config.php
	${INSTALL_DATA} ${FILESDIR}/.htaccess ${G2DIR}/.htaccess

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
