# $NetBSD: Makefile,v 1.2 2006/03/14 01:28:14 jlamwww Exp $

.include "../../mail/squirrelmail/plugin.mk"

PLUGIN_NAME=	change_ldappass
PLUGIN_VERSION=	1.8

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/plugin_view.php?id=26
COMMENT=	Allows users to change their LDAP password from SquirrelMail

DEPENDS+=	sm-compatibility>=1.3:../../wip/sm-compatibility
DEPENDS+=	php-ldap>=4.1.1:../../databases/php-ldap

CONF_FILES=	${FULL_PLUGIN_DIR}/config.php.sample \
		${FULL_PLUGIN_DIR}/config.php

.include "../../mk/bsd.pkg.mk"
