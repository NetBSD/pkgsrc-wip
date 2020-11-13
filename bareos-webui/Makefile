# $NetBSD: $

GITHUB_PROJECT=	bareos
VERSION=	19.2.8
GITHUB_TAG=	Release/${VERSION}

DISTNAME=	bareos-${VERSION}
PKGNAME=	${DISTNAME:S/-/-webui-/}
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:C/\//-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=bareos/}

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	http://www.bareos.org/
COMMENT=	PHP-Frontend to monitor and manage Bareos
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=5.4.0:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.4.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.4.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=5.4.0:../../devel/php-gettext

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_TOOLS+=	pax

WEBUI_DIR=	share/bareos-webui

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	nginx
APACHE_GROUP?=	nginx
BUILD_DEFS+=	APACHE_GROUP APACHE_USER

PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-install
SUBST_FILES.paths=	webui/config/autoload/global.php
SUBST_FILES.paths+=	webui/install/directors.ini
SUBST_FILES.paths+=	webui/install/configuration.ini
SUBST_FILES.paths+=	webui/install/apache/bareos-webui.conf
SUBST_FILES.paths+=	webui/install/nginx/bareos-webui.conf
SUBST_SED.paths=	-e 's,@WEBUICONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/usr/share/bareos-webui,${PREFIX}/share/bareos-webui,g'
SUBST_SED.paths+=	-e 's,/var/www/bareos-webui,${PREFIX}/share/bareos-webui,g'

SUBST_CLASSES+=		ports
SUBST_STAGE.ports=	pre-install
SUBST_FILES.ports=	webui/config/autoload/global.php
SUBST_FILES.ports+=	webui/install/directors.ini
SUBST_SED.ports=	-e 's,@dirport@,9101,g'

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-install
SUBST_FILES.version=	webui/version.php
SUBST_SED.version=	-e 's,@BAREOS_FULL_VERSION@,${VERSION},g'

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		WEBUI_DIR=${WEBUI_DIR}

EGDIR=		${PREFIX}/share/examples/bareos-webui
CONF_FILES+=	${EGDIR}/directors.ini ${PKG_SYSCONFDIR}/directors.ini
CONF_FILES+=	${EGDIR}/configuration.ini ${PKG_SYSCONFDIR}/configuration.ini

post-extract:
	${MV} ${WRKSRC}/webui/version.php.in ${WRKSRC}/webui/version.php
	${MV} ${WRKSRC}/webui/config/autoload/global.php.in ${WRKSRC}/webui/config/autoload/global.php
	${MV} ${WRKSRC}/webui/module/Application/view/layout/layout.phtml.in ${WRKSRC}/webui/module/Application/view/layout/layout.phtml
	${MV} ${WRKSRC}/webui/module/Application/view/layout/login.phtml.in ${WRKSRC}/webui/module/Application/view/layout/login.phtml
	${MV} ${WRKSRC}/webui/install/directors.ini.in ${WRKSRC}/webui/install/directors.ini
	${MV} ${WRKSRC}/webui/install/configuration.ini.in ${WRKSRC}/webui/install/configuration.ini

do-install:
	cd ${WRKSRC} && ${FIND} webui -type f \
		\! -name '.*' \
		\! -name 'CMakeLists.txt' \
		\! -path 'webui/phpunit.xml' \
		\! -path 'webui/debian/*' \
		\! -path 'webui/doc/*' \
		\! -path 'webui/cmake/*' \
		\! -path 'webui/doxygen/*' \
		\! -path 'webui/install/*' \
		\! -path 'webui/packaging/*' \
		\! -path 'webui/scripts/*' \
		\! -path 'webui/tests/*' \
		-print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share
	cd ${DESTDIR}${PREFIX}/share && mv webui bareos-webui
	cd ${WRKSRC}/webui/install && ${FIND} . -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/examples/bareos-webui
	cd ${WRKSRC}/webui/doc && ${FIND} . -type f -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share/doc/bareos-webui

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
