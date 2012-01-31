# $NetBSD: Makefile,v 1.6 2012/01/31 08:14:42 noud4 Exp $
#

DISTNAME=	dotproject-2.1.4
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dotproject/}

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://dotproject.sourceforge.net/
COMMENT=	Webserver base project management

WRKSRC=		${WRKDIR}/dotproject
USE_LANGUAGES=	# none

MYSQL_VERSIONS_ACCEPTED= 51 55 50

# base on PHP package
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.4.*:../../www/ap-php

# extensions buildable with both PHP 5.x
DEPENDS+=	${PHP_PKG_PREFIX}-apc>=4.4.*:../../www/php-apc
DEPENDS+=	${PHP_PKG_PREFIX}-eaccelerator>=4.4.*:../../www/php-eaccelerator
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.4.*:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.4.*:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdflib>=4.4.*:../../print/php-pdflib
DEPENDS+=	mysql-server>=4.1:../../databases/mysql${MYSQL_VERSION_DEFAULT}-server

META_PACKAGE=	yes

.include "../../lang/php/phpversion.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
