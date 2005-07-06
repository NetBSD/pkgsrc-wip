# $NetBSD: Makefile,v 1.1.1.1 2005/07/06 12:32:50 marttikuparinen Exp $

.include "../../mail/squirrelmail/plugin.mk"

PLUGIN_NAME=	change_qldforward
PLUGIN_VERSION=	1.00-1.2.0
PKGNAME=	sm-${PLUGIN_NAME}-${PLUGIN_VERSION:S/-/./}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/plugin_view.php?id=26
COMMENT=	Allows users to change their LDAP password from SquirrelMail

DEPENDS+=	sm-compatibility>=1.3:../../wip/sm-compatibility
DEPENDS+=	php-ldap>=4.1.1:../../databases/php-ldap

USE_PKGINSTALL=	yes

CONF_FILES=	${FULL_PLUGIN_DIR}/config.php.sample \
		${FULL_PLUGIN_DIR}/config.php

.include "../../mk/bsd.pkg.mk"
