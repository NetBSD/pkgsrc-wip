# $NetBSD: Makefile,v 1.1.1.1 2004/01/15 16:15:44 poppnk Exp $

DISTNAME=	SOAP-0.7.5
CATEGORIES=	www

MAINTAINER=	tech-kern@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/HTTP_Request
COMMENT=	SOAP Client/Server for PHP

DEPENDS+=	pear-Mail_Mime>=1.2:../../wip/pear-Mail_Mime
DEPENDS+=	pear-HTTP_Request>=1.2:../../wip/pear-HTTP_Request
DEPENDS+=	pear-Net_URL>=1.0:../../wip/pear-Net_URL
DEPENDS+=	pear-Net_DIME>=0.3:../../wip/pear-Net_DIME

.include "../../mk/bsd.prefs.mk"
.if defined(PEAR_USE_PHP5) && ${PEAR_USE_PHP5} == "YES"
.include "../../wip/php5/pear.mk"
.else
.include "../../www/php4/pear.mk"
.endif
.include "../../mk/bsd.pkg.mk"
