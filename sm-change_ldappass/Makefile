# $NetBSD: Makefile,v 1.5 2010/11/01 00:08:23 thomasklausner Exp $

.include "../../mail/squirrelmail/plugin.mk"

PLUGIN_NAME=	change_ldappass
PLUGIN_VERSION=	1.8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/plugin_view.php?id=26
COMMENT=	Allows users to change their LDAP password from SquirrelMail

DEPENDS+=	sm-compatibility>=1.3:../../wip/sm-compatibility
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.1.1:../../databases/php-ldap

CONF_FILES=	${FULL_PLUGIN_DIR}/config.php.sample \
		${FULL_PLUGIN_DIR}/config.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
