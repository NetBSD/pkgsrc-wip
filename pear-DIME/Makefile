# $NetBSD: Makefile,v 1.1.1.1 2004/01/15 16:18:15 poppnk Exp $

DISTNAME=	Net_DIME-0.3
CATEGORIES=	www

MAINTAINER=	tech-kern@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/HTTP_Request
COMMENT=	PHP classes that implements DIME encoding

.include "../../mk/bsd.prefs.mk"
.if defined(PEAR_USE_PHP5) && ${PEAR_USE_PHP5} == "YES"
.include "../../wip/php5/pear.mk"
.else
.include "../../www/php4/pear.mk"
.endif
.include "../../mk/bsd.pkg.mk"
