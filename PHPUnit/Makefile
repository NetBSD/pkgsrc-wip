# $NetBSD: Makefile,v 1.5 2014/09/27 03:02:25 obache Exp $

DISTNAME=	PHPUnit-3.7.22
CATEGORIES=	devel
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.phpunit.de/
COMMENT=	PHP regression testing framework for unit tests
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_CodeCoverage>=1.2.7:../../wip/pear-PHP_CodeCoverage
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Timer>=1.0.4:../../wip/pear-PHP_Timer
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHPUnit_MockObject>=1.2.2:../../wip/pear-PHPUnit_MockObject
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Yaml>=2.0.1:../../wip/pear-Yaml

.include "options.mk"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
