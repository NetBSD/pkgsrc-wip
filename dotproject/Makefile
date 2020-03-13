# $NetBSD: Makefile,v 1.9 2014/01/12 21:07:14 cheusov Exp $
#

DISTNAME=	dotproject-2.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dotproject/}

MAINTAINER=	hallmann@ahatec.de
HOMEPAGE=	http://dotproject.sourceforge.net/
COMMENT=	Webserver base project management
LICENSE=	gnu-gpl-v2

WRKSRC=				${WRKDIR}/dotproject
USE_LANGUAGES=			# none

MYSQL_VERSIONS_ACCEPTED=	55

# base on PHP package
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.4.0:../../www/ap-php

# extensions buildable with both PHP 5.x
DEPENDS+=	${PHP_PKG_PREFIX}-apc>=4.4.0:../../www/php-apc
# eaccelerator is gone from pkgsrc
BROKEN=		depends on missing www/php-eaccelerator package
#DEPENDS+=	${PHP_PKG_PREFIX}-eaccelerator>=4.4.0:../../www/php-eaccelerator
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.4.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdflib>=4.4.0:../../print/php-pdflib

.include "../../lang/php/phpversion.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
