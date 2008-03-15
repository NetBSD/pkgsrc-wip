# $NetBSD: Makefile,v 1.1 2008/03/15 11:42:52 ahallmann Exp $
#

DISTNAME=	dotproject-2.1.1
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dotproject/}

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://dotproject.sourceforge.net/
COMMENT=	Webserver base project management

WRKSRC=		${WRKDIR}/dotproject
USE_LANGUAGES=	# none


# This package needs PHP4 and mysql4.
# Even so ports to PHP5 and mysql5 are on the way, they can't be considered stable.  (as of march 2008)

MYSQL_VERSIONS_ACCEPTED= 41

# base on PHP 4.x package
DEPENDS+=	php-4.4.*:../../www/php4
DEPENDS+=	${APACHE_PKG_PREFIX}-php4-4.4.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php4-apc-4.4.*:../../www/php4-apc
DEPENDS+=	php4-eaccelerator-4.4.*:../../www/php-eaccelerator
DEPENDS+=	php4-gd-4.4.*:../../graphics/php-gd
DEPENDS+=	php4-zlib-4.4.*:../../archivers/php-zlib
DEPENDS+=	php4-mysql-4.4.*:../../databases/php-mysql
DEPENDS+=	php4-pdflib-4.4.*:../../print/php-pdflib
DEPENDS+=	mysql4-server-4.1.*:../../databases/mysql4-server


META_PACKAGE=	yes

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
