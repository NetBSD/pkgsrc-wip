# $NetBSD: Makefile,v 1.2 2004/10/09 17:25:22 dolecek Exp $

DISTNAME=	Net_URL-1.0.10
CATEGORIES=	www

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Net_URL/
COMMENT=	PHP classes to easy parsing of Urls

.include "../../mk/bsd.prefs.mk"
.if defined(PEAR_USE_PHP5) && ${PEAR_USE_PHP5} == "YES"
.include "../../wip/php5/pear.mk"
.else
.include "../../www/php4/pear.mk"
.endif
.include "../../mk/bsd.pkg.mk"
