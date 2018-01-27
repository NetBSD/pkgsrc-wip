# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $

DISTNAME=	FinderFacade-1.1.0
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pear.phpunit.de/
COMMENT=	Convenience wrapper for Symfony\'s Finder component

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit
DEPENDS+=	${PHP_PKG_PREFIX}-pear-fDOMDocument>=1.3.1:../../wip/pear-fDOMDocument
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Finder>=2.2.0:../../wip/pear-Finder

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
