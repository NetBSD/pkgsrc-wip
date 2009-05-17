# $NetBSD: Makefile,v 1.5 2009/05/17 18:23:45 rewts Exp $
#

DISTNAME=	SugarCE-${VERSION}
PKGNAME=	sugarCRM-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://www.sugarforge.org/frs/download.php/5446/
EXTRACT_SUFX=	.zip

MAINTAINER=	derv0@nubisci.net
HOMEPAGE=	http://www.sugarcrm.com/
COMMENT=	SugarCRM is a php based CRM system

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql

VERSION=	5.2.0e

USE_LANGUAGES=	# empty
NO_BUILD=	yes
WRKSRC=	${WRKDIR}/SugarCE-Full-5.2.0e

APACHE_USER?=	www
APACHE_GROUP?=	www
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sugarCRM
	${CP} -R ${WRKSRC}/* ${PREFIX}/share/sugarCRM
	${CHOWN} -R ${APACHE_USER}:${APACHE_GROUP} ${PREFIX}/share/sugarCRM

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
