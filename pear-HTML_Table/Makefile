# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:49 asau Exp $

DISTNAME=	HTML_Table-1.8.3
CATEGORIES=	www

MAINTAINER=	wenheping@gmail.com
COMMENT=	Makes the design of HTML tables easy, flexible, reusable and efficient

CONFLICTS=	php-pear-HTML_Common-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
