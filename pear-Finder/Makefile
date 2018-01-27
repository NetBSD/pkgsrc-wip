# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $

DISTNAME=	Finder-2.3.1
CATEGORIES=	www
MASTER_SITES+=	http://pear.symfony.com/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://symfony.com/
COMMENT=	Symfony2 Finder Component
LICENSE=	mit

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-symfony2-[0-9]*:../../wip/pear-channel-symfony

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
