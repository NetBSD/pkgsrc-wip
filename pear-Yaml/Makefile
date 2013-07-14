# $NetBSD: Makefile,v 1.1 2013/07/14 11:43:35 noud4 Exp $

DISTNAME=	Yaml-2.3.1
CATEGORIES=	www
MASTER_SITES+=	http://pear.symfony.com/get/

MAINTAINER=	noud4@home.nl
HOMEPAGE= 	http://symfony.com/components
COMMENT=	Symfony2 Yaml Component
LICENSE=	mit

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-symfony2-[0-9]*:../../wip/pear-channel-symfony

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
