# $NetBSD: Makefile,v 1.3 2006/03/14 01:28:15 jlamwww Exp $
#

DISTNAME=	SugarSuite-Full-${VERSION}
PKGNAME=	sugarCRM-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://www.sugarforge.org/frs/download.php/235/
EXTRACT_SUFX=	.zip

MAINTAINER=	ma@arconsulting.com.au
HOMEPAGE=	http://www.sugarforge.org/frs/download.php/235/
COMMENT=	SugarCRM is a php based CRM system

DEPENDS+=	php-mysql>=4.3.3:../../databases/php-mysql

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

.include "../../mk/bsd.pkg.mk"
