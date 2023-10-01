# $NetBSD$

.include "../../wip/zabbix64-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-frontend-${ZABBIX_DB_TYPE}-/}
COMMENT=	Zabbix PHP 7.4+ frontend

PATCHDIR=       "../../wip/zabbix64-server/patches"
DISTINFO_FILE=  "../../wip/zabbix64-server/distinfo"

CONFLICTS+=	zabbix-frontend-[0-9]*

EGDIR=		share/examples/${PKGBASE}

USE_TOOLS+=		pax
NO_BUILD=		yes
NO_CONFIGURE=		yes

REPLACE_SH+=	ui/locale/*.sh

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

BUILD_DEFS+=		APACHE_GROUP APACHE_USER
PKG_GROUPS_VARS+=	${APACHE_GROUP}
PKG_USERS_VARS=		${APACHE_USER}

PHP_VERSIONS_ACCEPTED=	80 81 82

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=8.0.0:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=8.0.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=8.0.0:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=8.0.0:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=8.0.0:../../converters/php-mbstring
.if ${ZABBIX_DB_TYPE} == "mysql"
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=8.0.0:../../databases/php-mysqli
.endif
.if ${ZABBIX_DB_TYPE} == "pgsql"
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=8.0.0:../../databases/php-pgsql
.endif
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=8.0.0:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=8.0.0:../../devel/php-sysvsem

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

post-patch: replace-interpreter

do-install:
	rm -f ${WRKSRC}/ui/locale/*.orig
	cd ${WRKSRC}/ui; ${PAX} -rw . ${DESTDIR}${PREFIX}/share/zabbix/
	${INSTALL_DATA} ${FILESDIR}/httpd-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/php-fpm-zabbix.conf ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/configure/replace-interpreter.mk"
.include "../../mk/bsd.pkg.mk"
