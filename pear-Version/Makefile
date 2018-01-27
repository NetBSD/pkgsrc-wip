# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:10 noud4 Exp $
#

DISTNAME=	Version-1.0.1
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pear.phpunit.de/
COMMENT=	Library that helps with managing the version number of Git-hosted PHP projects	
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpunit-[0-9]*:../../wip/pear-channel-phpunit

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
