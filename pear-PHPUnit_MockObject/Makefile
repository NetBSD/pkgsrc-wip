# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $
#

DISTNAME=	PHPUnit_MockObject-1.2.3
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpunit.de/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pear.phpunit.de/
COMMENT=	Mock Object library for PHPUnit
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Text_Template>=1.1.1:../../wip/pear-Text_Template

.include "options.mk"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
