# $NetBSD$

# TODO
# rc.d file?
# mention php.ini mods in MESSAGE and mysql setup
# need working git + mozilla-rootcerts ?
DISTNAME=		phabricator-20160221
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		http://phabricator.com/
COMMENT=		Open software engineering platform
LICENSE=		apache-2.0

WRKSRC=			${WRKDIR}/phabricator

USE_TOOLS+=		pax

DEPENDS+=		${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=		${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=		${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=		${PHP_PKG_PREFIX}-mysql-[0-9]*:../../databases/php-mysql
DEPENDS+=		${PHP_PKG_PREFIX}-pcntl-[0-9]*:../../devel/php-pcntl
DEPENDS+=		${PHP_PKG_PREFIX}-posix-[0-9]*:../../devel/php-posix
DEPENDS+=		${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=		${PHP_PKG_PREFIX}-zendopcache-[0-9]*:../../www/php-zendopcache
DEPENDS+=		${PHP_PKG_PREFIX}-apcu-[0-9]*:../../www/php-apcu
#DEPENDS+=		:../../textproc/py-pygments?
DEPENDS+=		libphutil-[0-9]*:../../wip/libphutil
DEPENDS+=		arcanist-[0-9]*:../../wip/arcanist

SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	externals/httpful/build
SUBST_FILES.php+=	externals/restful/build-phar
SUBST_SED.php=		-e 's,/usr/bin/php,${PREFIX}/bin/php,'

SUBST_CLASSES+=		php_env
SUBST_MESSAGE.php_env=	Fixing PHP path
SUBST_STAGE.php_env=	post-configure
SUBST_FILES.php_env+=	scripts/almanac/manage_almanac.php \
			scripts/cache/manage_cache.php \
			scripts/calendar/import_us_holidays.php \
			scripts/celerity/generate_sprites.php \
			scripts/daemon/*.php \
			scripts/diviner/diviner.php \
			scripts/drydock/drydock_control.php \
			scripts/fact/manage_facts.php \
			scripts/files/manage_files.php \
			scripts/lipsum/manage_lipsum.php \
			scripts/mail/*.php \
			scripts/repository/*.php \
			scripts/search/manage_search.php \
			scripts/setup/*.php \
			scripts/sms/manage_sms.php \
			scripts/sql/manage_storage.php \
			scripts/ssh/*.php \
			scripts/symbols/*.php \
			scripts/user/*.php \
			scripts/util/*.php \
			support/aphlict/server/aphlict_launcher.php 
SUBST_SED.php_env=	-e 's,/usr/bin/env php,${PREFIX}/bin/php,'


REPLACE_PYTHON+=	externals/twilio-php/docs/_themes/flask_theme_support.py \
			externals/twilio-php/docs/conf.py

CHECK_INTERPRETER_SKIP+=	externals/wordlist/password.lst

NO_BUILD=		yes

PHABRICATOR_DIR=	${PREFIX}/share/phabricator

AUTO_MKDIRS=		yes

do-install:
			cd ${WRKSRC} && pax -rw -pe * ${DESTDIR}${PHABRICATOR_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
