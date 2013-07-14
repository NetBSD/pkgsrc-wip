# $NetBSD: Makefile,v 1.1 2013/07/14 12:24:24 noud4 Exp $

DISTNAME=	FinderFacade-1.1.0
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://pear.phpunit.de/
COMMENT=	Convenience wrapper for Symfony\'s Finder component

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit
DEPENDS+=	${PHP_PKG_PREFIX}-pear-fDOMDocument>=1.3.1:../../wip/pear-fDOMDocument
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Finder>=2.2.0:../../wip/pear-Finder

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
