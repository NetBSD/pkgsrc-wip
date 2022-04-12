# $NetBSD$

DISTNAME=	basercms-4.5.6
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=baserproject/}
GITHUB_PROJECT=	basercms
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://basercms.net/
COMMENT=	Based Website Development Project
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.6.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.6.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.6.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.6.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.6.0:../../archivers/php-zip

.include "options.mk"

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

NO_BUILD=	yes
USE_TOOLS+=	bash:run pax

BASERCMS_DIR=	share/basercms

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		BASERCMS_DIR=${BASERCMS_DIR}

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*php[^ ]*
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	app/Console/cake.php
REPLACE_FILES.php+=	lib/Cake/Console/Templates/skel/Console/cake.php
REPLACE_FILES.php+=	lib/Cake/Console/cake.php

INSTALLATION_DIRS=	${BASERCMS_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${BASERCMS_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../lang/php/json.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
