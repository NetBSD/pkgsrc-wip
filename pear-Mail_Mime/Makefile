# $NetBSD: Makefile,v 1.2 2004/10/09 17:25:15 dolecek Exp $

DISTNAME=	Mail_Mime-1.2.1
CATEGORIES=	www

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Mail_Mime/
COMMENT=	PHP classes to create and decode mime messages

.include "../../mk/bsd.prefs.mk"
.if defined(PEAR_USE_PHP5) && ${PEAR_USE_PHP5} == "YES"
.include "../../wip/php5/pear.mk"
.else
.include "../../www/php4/pear.mk"
.endif
.include "../../mk/bsd.pkg.mk"
