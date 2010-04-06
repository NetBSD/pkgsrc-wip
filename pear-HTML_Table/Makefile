# $NetBSD: Makefile,v 1.1.1.1 2010/04/06 13:17:36 uccwen Exp $

DISTNAME=	HTML_Table-1.8.3
CATEGORIES=	www

MAINTAINER=	wenheping@gmail.com
COMMENT=	Makes the design of HTML tables easy, flexible, reusable and efficient

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-HTML_Common-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
