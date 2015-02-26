# $NetBSD: Makefile,v 1.2 2015/02/26 06:49:15 makoto Exp $

DISTNAME=		2.11.1
PKGNAME=		piwik-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		https://github.com/piwik/piwik/archive/
DIST_SUBDIR=		piwik

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/piwik
COMMENT=		Open Source Analytics
LICENSE=		gnu-gpl-v3

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		pkg-config pax
NO_BUILD=		yes

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}
PKG_GROUPS_VARS=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER

BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP
EGDIR=			${PREFIX}/share/examples/piwik
DOCDIR=			${PREFIX}/share/doc/piwik
# User may set DocumentRoot in ${PREFIX}/etc/httpd/httpd.conf to following path
PKHOME=			${PREFIX}/share/piwik
FILES_SUBST+=		PKHOME=${PKHOME}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

DEPENDS+=	php5[0-9]-zlib-[0-9]*:../../archivers/php-zlib
DEPENDS+=	php5[0-9]-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	php5[0-9]-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	php5[0-9]-json-[0-9]*:../../textproc/php-json
DEPENDS+=	php5[0-9]-curl-[0-9]*:../../www/php-curl
DEPENDS+=	php5[0-9]-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	php5[0-9]-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=	php5[0-9]-mbstring-[0-9]*:../../converters/php-mbstring
#DEPENDS+=	php5[0-9]-cli-[0-9]*:../../databases/php-cli
DEPENDS+=	php5[0-9]-geoip-[0-9]*:../../net/php-geoip
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

PHP_VERSIONS_ACCEPTED= 54 55 56
#PHP_VERSION_REQD= 56

# Add line to ${PREFIX}/etc/php.ini for above
# extension=json.so
DEPENDS+=	php5[0-9]-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	ap22-php5[0-9]*-[0-9]*:../../www/ap-php

REPLACE_BASH=	tests/lib/mocha-1.17.1/test/acceptance/glob/glob.sh
REPLACE_BASH+=	tests/travis/generate_docs.sh

REPLACE_BASH+=	libs/jqplot/build_minified_script.sh

REPLACE_BASH+=	misc/composer/*.sh
REPLACE_BASH+=	misc/cron/archive.sh
REPLACE_BASH+=	misc/log-analytics/tests/run_tests.sh
REPLACE_BASH+=	misc/others/stress.sh

REPLACE_BASH+=	plugins/TestRunner/scripts/on_instance_launch.sh

REPLACE_BASH+=	tests/PHPUnit/travis.sh
REPLACE_BASH+=	tests/angularjs/scripts/*.sh
REPLACE_BASH+=	tests/javascript/jash

REPLACE_BASH+=	tests/lib/chai-1.9.0/support/sauce/*.sh
REPLACE_BASH+=	tests/lib/jsdoc-toolkit/jsrun.sh
REPLACE_BASH+=	tests/lib/mocha-1.17.1/test/acceptance/glob/glob.sh

REPLACE_BASH+=	tests/travis/*.sh

#REPLACE_PHP+=	console

REPLACE_PYTHON+=misc/log-analytics/import_logs.py

do-install:
	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}${PKHOME}
	${FIND} ${DESTDIR}${PKHOME} \
		-type d -exec ${CHMOD} ${PKGDIRMODE} "{}" \;
	${FIND} ${DESTDIR}${PKHOME} \
		-type f -exec ${CHMOD} ${SHAREMODE} "{}" \;

.include "../../lang/python/application.mk"
# to give PHP_VERSION_DEFAULT
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"

## wip/piwik/work/.destdir/usr/pkg/share/piwik/tests/lib/mocha-1.17.1/bin/_mocha
## wip/piwik/work/.destdir/usr/pkg/share/piwik/tests/lib/mocha-1.17.1/bin/mocha
