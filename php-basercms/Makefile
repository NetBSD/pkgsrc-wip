# $NetBSD$

BASERVER=	5.2.0
DISTNAME=	basercms-${BASERVER}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=baserproject/}
GITHUB_PROJECT=	basercms
GITHUB_TAG=	${BASERVER}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://basercms.net/
COMMENT=	Easy to use Content Management System for Japan/Japanese
LICENSE=	mit

PHP_VERSIONS_ACCEPTED=	81 82 83 84

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=8.1.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=8.1.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=8.1.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=8.1.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=8.1.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=8.1.0:../../archivers/php-zip

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}
USE_LANGUAGES=		# none

USE_TOOLS+=	bash:run pax

NO_BUILD=	yes

CHECK_INTERPRETER_SKIP+=	share/basercms/app/Console/*
CHECK_INTERPRETER_SKIP+=	share/basercms/lib/Cake/Console/*

BC_DIR=		share/basercms
INSTALLATION_DIRS+=	${BC_DIR}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		BC_DIR=${BC_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/${BC_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../lang/php/json.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
