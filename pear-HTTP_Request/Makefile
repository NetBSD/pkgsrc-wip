# $NetBSD: Makefile,v 1.1.1.1 2004/01/15 16:16:29 poppnk Exp $

DISTNAME=	HTTP_Request-1.2
CATEGORIES=	www

MAINTAINER=	tech-kern@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/HTTP_Request
COMMENT=	PHP classes to provides an easy way to perform HTTP requests

DEPENDS+=	pear-Net_Socket>=1.0:../../wip/pear-Net_Socket
DEPENDS+=	pear-Net_URL>=1.0:../../wip/pear-Net_URL

.include "../../mk/bsd.prefs.mk"
.if defined(PEAR_USE_PHP5) && ${PEAR_USE_PHP5} == "YES"
.include "../../wip/php5/pear.mk"
.else
.include "../../www/php4/pear.mk"
.endif
.include "../../mk/bsd.pkg.mk"
