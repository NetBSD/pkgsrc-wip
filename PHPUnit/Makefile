# $NetBSD: Makefile,v 1.2 2010/08/29 06:10:25 obache Exp $

DISTNAME=	PHPUnit-3.4.15
CATEGORIES+=	devel
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.phpunit.de/
COMMENT=	PHP regression testing framework for unit tests
LICENSE=	modified-bsd

BUILD_DEPENDS+=		${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit
DEPENDS+=		${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
