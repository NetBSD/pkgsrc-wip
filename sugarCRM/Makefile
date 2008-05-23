# $NetBSD: Makefile,v 1.4 2008/05/23 10:32:36 tnn2 Exp $
#

DISTNAME=	SugarSuite-Full-${VERSION}
PKGNAME=	sugarCRM-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://www.sugarforge.org/frs/download.php/235/
EXTRACT_SUFX=	.zip

MAINTAINER=	ma@arconsulting.com.au
HOMEPAGE=	http://www.sugarforge.org/frs/download.php/235/
COMMENT=	SugarCRM is a php based CRM system

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

VERSION=	3.0.1a

USE_LANGUAGES=	# empty
NO_BUILD=	yes

APACHE_USER?=	www
APACHE_GROUP?=	www
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sugarCRM
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/sugarCRM
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${PREFIX}/share/sugarCRM

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
