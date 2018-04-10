# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:10 noud4 Exp $
#

DISTNAME=	phpdcd-0.9.3
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pear.phpunit.de/
COMMENT=	Dead Code Detector (DCD) for PHP code
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-File_Iterator>=1.3.0:../../wip/pear-File_Iterator
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Timer>=1.0.1:../../wip/pear-PHP_Timer
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_TokenStream>=1.1.0:../../wip/pear-PHP_TokenStream
DEPENDS+=	${PHP_PKG_PREFIX}-pear-ConsoleTools>=1.6:../../wip/pear-ConsoleTools

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
