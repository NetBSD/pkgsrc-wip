# $NetBSD: Makefile,v $

DISTNAME=	icingaweb2-2.12.6
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=icinga/}
CATEGORIES=	net sysutils www

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://github.com/Icinga/icingaweb2
COMMENT=	PHP-based Web UI for Icinga
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-imagick-[0-9]*:../../graphics/php-imagick
DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
# For php-*sql see options.mk
DEPENDS+=	${PHP_PKG_PREFIX}-icinga-php-library>=0.14.2<1:../../wip/icinga-php-library
DEPENDS+=	${PHP_PKG_PREFIX}-icinga-php-thirdparty>=0.12.0<1:../../wip/icinga-php-thirdparty

PHP_REQUIRE_MODULE=	json

PHP_VERSIONS_ACCEPTED=	82 83 84

USE_TOOLS+=	pax

USE_LANGUAGES=	# empty
NO_BUILD=	YES

# Can't set NO_CONFIGURE=YES since REPLACE_INTERPRETER needs a configure phase
do-configure:

PKG_USERS_VARS+=		APACHE_USER

PKG_SYSCONFSUBDIR=		icingaweb2
EGDIR=				${PREFIX}/share/examples/icingaweb2
SHAREDIR=			${PREFIX}/share/icingaweb2
INCDIR=				${PREFIX}/${PHP_LIBDIR}
INSTALLATION_DIRS+=		${PREFIX}/bin ${EGDIR} ${SHAREDIR}
STORAGEDIR=			${VARBASE}/db/icingaweb2
LOGDIR=				${VARBASE}/log/icingaweb2
OWN_DIRS_PERMS+=		${STORAGEDIR} ${APACHE_USER} ${REAL_ROOT_GROUP} 0755
OWN_DIRS_PERMS+=		${LOGDIR} ${APACHE_USER} ${REAL_ROOT_GROUP} 0755
RUNDIR_PARENT=			${VARBASE}/run
EDITOR=				vi
PKG_SYSCONFDIR.icinga2?=	${PKG_SYSCONFBASE}/icinga2

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# The upstream distribution is not exactly packaging-friendly. It's kind of a blob, no Makefile, no configuration, everything-is-Linux mindset. Hard-coded paths everywhere, #!/usr/bin/env etc.
# Debian (upstream's main target) splits it into a bunch of packages, namely icingaweb2, icingaweb2-common, icingaweb2-module-doc, icingaweb2-module-monitoring (no -module-translation, that's in -common), icingacli (no "web" or "2").
# Most files go to /usr/share/icingaweb2, but to make it even more interesting, files in the php-icinga package are relocated from the library/Icinga subdiretory of the distribution to /usr/share/php/Icinga (but other files in that package go to /usr/share/icingaweb2/library).
# Some files aren't even installed at all.
# There are also no example configuration files.

# Install example configuration files.
# Contents taken from the "Advanced Topics: Icinga Web 2 Manual Setup: Icinga Web 2 Manual Configuration" and other manual sections.
CONFS=		roles.ini resources.ini config.ini authentication.ini groups.ini roles.ini
CONFDIRS=	modules modules/monitoring
CONFS+=		modules/monitoring/config.ini modules/monitoring/backends.ini modules/monitoring/commandtransports.ini
CONFDIRS+=	enabledModules
# symlinks in enabledModules?

# for extraction, see post-extract below

SUBST_CLASSES+=			sampleconfig-db
SUBST_STAGE.sampleconfig-db=	pre-configure
SUBST_MESSAGE.sampleconfig-db=	Fixing DB in config examples.
SUBST_FILES.sampleconfig-db=	etc/examples/resources.ini
# If compiled with MySQL support, use MySQL example, else PgSQL.
.if !empty(PKG_OPTIONS:Mmysql)
SUBST_SED.sampleconfig-db=	-e 's,@DB_TYPE@,mysql,g'
SUBST_SED.sampleconfig-db+=	-e 's,@DB_PORT@,3306,g'
.else
SUBST_SED.sampleconfig-db=	-e 's,@DB_TYPE@,pgsql,g'
SUBST_SED.sampleconfig-db+=	-e 's,@DB_PORT@,5432,g'
.endif

SUBST_CLASSES+=				sampleconfig-path
SUBST_STAGE.sampleconfig-path=		pre-configure
SUBST_MESSAGE.sampleconfig-path=	Fixing paths in config examples.
SUBST_FILES.sampleconfig-path=		etc/examples/config.ini
SUBST_VARS.sampleconfig-path=		SHAREDIR LOGDIR

# for installation of the example configuration files, see do-install below

.for d in ${CONFDIRS}
OWN_DIRS+=	${PKG_SYSCONFDIR}/${d}
.endfor

.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Remove unneeded files in directories that are installed
RMFILES=	application/fonts/fontello-ifont/config.json application/fonts/fontello-ifont/demo.html
RMFILES+=	application/fonts/fontello-ifont/font/ifont.eot application/fonts/fontello-ifont/font/ifont.svg application/fonts/fontello-ifont/font/ifont.ttf application/fonts/fontello-ifont/font/ifont.woff application/fonts/fontello-ifont/font/ifont.woff2
RMFILES+=	application/fonts/fontello-ifont/LICENSE.txt application/fonts/fontello-ifont/README.txt
RMFILES+=	application/fonts/icingaweb.md
RMFILES+=	application/VERSION
# for actual removal, see post-extract below

REPLACE_PHP+=		bin/icingacli			# /usr/bin/env php

# We need a lot of SUBSTs. The list of hard-coded paths was gathered along the lines of "grep -rF '/etc/' . | sed -n -e 's:^.*/etc/\([^/]*\)/.*$:\1:p' | sort | uniq" etc., plus manual inspection.
# See below for a descrption what is NOT substituted.

SUBST_CLASSES+=			schema
SUBST_STAGE.schema=		pre-configure
SUBST_MESSAGE.schema=		Fixing schema paths.
SUBST_FILES.schema+=		doc/80-Upgrading.md
SUBST_SED.schema=		-e 's,/usr/share/doc/icingaweb2,${SHAREDIR}/etc,g'

SUBST_CLASSES+=			sharedir
SUBST_STAGE.sharedir=		pre-configure
SUBST_MESSAGE.sharedir=		Fixing SHAREDIR paths.
SUBST_FILES.sharedir=		doc/02-Installation.md
SUBST_FILES.sharedir+=		doc/03-Configuration.md
SUBST_FILES.sharedir+=		doc/08-Modules.md
SUBST_FILES.sharedir+=		doc/20-Advanced-Topics.md
SUBST_FILES.sharedir+=		doc/80-Upgrading.md
SUBST_FILES.sharedir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_FILES.sharedir+=		public/error_unavailable.html
SUBST_SED.sharedir=		-e 's,/usr/share/icingaweb2,${SHAREDIR},g'

SUBST_CLASSES+=			storagedir
SUBST_STAGE.storagedir=		pre-configure
SUBST_MESSAGE.storagedir=	Fixing STORAGEDIR paths.
SUBST_FILES.storagedir=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_SED.storagedir=		-e 's,/var/lib/icingaweb2,${STORAGEDIR},g'

.if ${LOGDIR} != "/var/log/icingaweb2"
SUBST_CLASSES+=			logdir
SUBST_STAGE.logdir=		pre-configure
SUBST_MESSAGE.logdir=		Fixing LOGDIR paths.
SUBST_FILES.logdir=		application/forms/Config/General/LoggingConfigForm.php
SUBST_SED.logdir=		-e 's,/var/log/icingaweb2,${LOGDIR},g'
.endif

.if ${RUNDIR_PARENT} != "/var/run"
SUBST_CLASSES+=			rundir
SUBST_STAGE.rundir=		pre-configure
SUBST_MESSAGE.rundir=		Fixing RUNDIR paths.
SUBST_FILES.rundir=		doc/04-Resources.md
SUBST_FILES.rundir+=		modules/monitoring/application/forms/Config/Transport/LocalTransportForm.php
SUBST_FILES.rundir+=		modules/monitoring/application/forms/Config/Transport/RemoteTransportForm.php
SUBST_FILES.rundir+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_FILES.rundir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_SED.rundir=		-e 's,/var/run,${RUNDIR_PARENT},g'
.endif

# This is kind of gross, but occurs only in documentation and the setup tool
SUBST_CLASSES+=			apache2
SUBST_STAGE.apache2=		pre-configure
SUBST_MESSAGE.apache2=		Fixing Apache2 config paths.
SUBST_FILES.apache2=		doc/02-Installation.md
SUBST_FILES.apache2+=		doc/20-Advanced-Topics.md
SUBST_FILES.apache2+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_SED.apache2=		-e 's,/etc/apache2,${PREFIX}/etc/httpd,g'
SUBST_SED.apache2+=		-e 's,/etc/httpd,${PREFIX}/etc/httpd,g'

SUBST_CLASSES+=			icinga2
SUBST_STAGE.icinga2=		pre-configure
SUBST_MESSAGE.icinga2=		Fixing Icinga2 config paths.
SUBST_FILES.icinga2=		modules/monitoring/doc/05-Command-Transports.md
SUBST_SED.icinga2=		-e 's,/etc/icinga2,${PKG_SYSCONFDIR.icinga2},g'

SUBST_CLASSES+=			confdir
SUBST_STAGE.confdir=		pre-configure
SUBST_MESSAGE.confdir=		Fixing config paths.
SUBST_FILES.confdir=		doc/02-Installation.md
SUBST_FILES.confdir+=		doc/03-Configuration.md
SUBST_FILES.confdir+=		doc/04-Resources.md
SUBST_FILES.confdir+=		doc/05-Authentication.md
SUBST_FILES.confdir+=		doc/06-Security.md
SUBST_FILES.confdir+=		doc/08-Modules.md
SUBST_FILES.confdir+=		doc/20-Advanced-Topics.md
SUBST_FILES.confdir+=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_FILES.confdir+=		modules/monitoring/doc/03-Configuration.md
SUBST_FILES.confdir+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_FILES.confdir+=		modules/setup/application/clicommands/ConfigCommand.php
SUBST_FILES.confdir+=		modules/setup/application/clicommands/TokenCommand.php
SUBST_FILES.confdir+=		modules/setup/application/views/scripts/form/setup-welcome.phtml
SUBST_FILES.confdir+=		modules/setup/library/Setup/WebWizard.php
SUBST_SED.confdir=		-e 's,/etc/icingaweb2,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=			php-inc
SUBST_STAGE.php-inc=		pre-configure
SUBST_MESSAGE.php-inc=		Fixing PHP include paths.
SUBST_FILES.php-inc=		bin/icingacli
SUBST_FILES.php-inc+=		public/index.php
# The original reads "require_once dirname(__DIR__) . '/library/Icinga/Application/XXX.php';"
SUBST_SED.php-inc=		-e 's,dirname(__DIR__) \. ,,'
SUBST_SED.php-inc+=		-e 's,/library,${INCDIR},'

SUBST_CLASSES+=			php-inc2
SUBST_STAGE.php-inc2=		pre-configure
SUBST_MESSAGE.php-inc2=		Fixing more PHP include paths.
SUBST_FILES.php-inc2=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_SED.php-inc2=		-e 's,/usr/share/icinga-php,${INCDIR}/icinga-php,'

# There are no L10n files yet, but fix the path anyway
SUBST_CLASSES+=			l10n
SUBST_STAGE.l10n=		pre-configure
SUBST_MESSAGE.l10n=		Fixing L10n paths.
SUBST_FILES.l10n=		library/Icinga/Application/ApplicationBootstrap.php
SUBST_SED.l10n=			-e 's,/usr/share/icinga-L10n/,${PREFIX}/share/icinga-L10n/,'

# These could be based on a "translation" option. It's used for msgfmt, msgmerge and xgettext
SUBST_CLASSES+=			env-gettext
SUBST_STAGE.env-gettext=	pre-configure
SUBST_MESSAGE.env-gettext=	Fixing env usage.
SUBST_FILES.env-gettext=	modules/translation/library/Translation/Util/GettextTranslationHelper.php
SUBST_SED.env-gettext=		-e 's,/usr/bin/env ,/bin/,g'

# While there, we can fix references to vim, too
SUBST_CLASSES+=			vim
SUBST_STAGE.vim=		pre-configure
SUBST_MESSAGE.vim=		Fixing vim references.
SUBST_FILES.vim=		doc/05-Authentication.md
SUBST_FILES.vim+=		doc/20-Advanced-Topics.md
SUBST_FILES.vim+=		modules/monitoring/doc/03-Configuration.md
SUBST_FILES.vim+=		modules/monitoring/doc/05-Command-Transports.md
SUBST_SED.vim=			-e 's,vim /,${EDITOR} /,g'

# There is also some hard-coded paths that are NOT substituted:
# -- paths that are Linux-specific enyway: /usr/lib/os-release, /etc/apt, /etc/audit, /etc/opt
# -- paths where the usage seems OK: /usr/share/{file,misc,mime}/magic{,.mime,.mgc}, /tmp, /proc/self

# post-extract jobs
post-extract:
	${MKDIR} ${WRKSRC}/etc/examples
.for d in ${CONFDIRS}
	${MKDIR} ${WRKSRC}/etc/examples/${d}
.endfor
.for f in ${CONFS}
	${CP} ${FILESDIR}/${f} ${WRKSRC}/etc/examples/${f}
.endfor
.for f in ${RMFILES}
	${RM} ${WRKSRC}/${f}
.endfor

# Remove .orig file so it doesn't get installed
post-patch:
	${RM} ${WRKSRC}/library/Icinga/Application/webrouter.php.orig

# Install the files
do-install:
	cd ${WRKSRC} && ${PAX} -rw -pmp application doc schema modules/doc modules/migrate modules/monitoring modules/setup modules/translation public ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/public/index.php ${DESTDIR}${SHAREDIR}/public/index.php
	cd ${WRKSRC}/library && ${PAX} -rw -pmp Icinga ${DESTDIR}${INCDIR}
	cd ${WRKSRC}/etc/examples && ${PAX} -rw -pmp . ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/icingacli ${DESTDIR}${PREFIX}/bin/icingacli

PLIST_SUBST+=	SHAREDIR="${SHAREDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	INCDIR="${INCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	EGDIR="${EGDIR:S.${PREFIX}/..}"

GENERATE_PLIST+=	printf "${EGDIR:S.${PREFIX}/..}/%s\n" ${CONFS};

.include "../../lang/php/compat.mk"
.include "../../mk/bsd.pkg.mk"
