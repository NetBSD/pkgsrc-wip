# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:10 noud4 Exp $

DISTNAME=	Yaml-2.3.1
CATEGORIES=	www
MASTER_SITES+=	http://pear.symfony.com/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://symfony.com/components
COMMENT=	Symfony2 Yaml Component
LICENSE=	mit

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-symfony2-[0-9]*:../../wip/pear-channel-symfony

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
