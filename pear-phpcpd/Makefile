# $NetBSD: Makefile,v 1.1 2013/07/14 12:36:14 noud4 Exp $
#

DISTNAME=	phpcpd-1.4.1
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.phpunit.de/
COMMENT=	Copy/Paste Detector (CPD) for PHP code
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-ConsoleTools>=1.5.1:../../wip/pear-ConsoleTools
DEPENDS+=	${PHP_PKG_PREFIX}-pear-FinderFacade>=1.0.5:../../wip/pear-FinderFacade
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Timer>=1.0.4:../../wip/pear-PHP_Timer
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Version>=1.0.1:../../wip/pear-Version

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
