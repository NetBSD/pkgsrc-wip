# $NetBSD: Makefile,v 1.2 2013/12/10 13:19:26 noud4 Exp $
#

DISTNAME=	PHP_Invoker-1.1.3
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.phpunit.de/
COMMENT=	Utility class for invoking callables with a timeout
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Timer>=1.0.4:../../wip/pear-PHP_Timer
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl-[0-9]*:../../devel/php-pcntl

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
