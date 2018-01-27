# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $
#

DISTNAME=	PHP_PMD-1.4.1
CATEGORIES=	devel
MASTER_SITES+=	http://pear.phpmd.org/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://phpmd.org/
COMMENT=	PHP Mess Detector
LICENSE=	original-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-phpmd-[0-9]*:../../wip/pear-channel-phpmd
DEPENDS+=	${PHP_PKG_PREFIX}-pear-PHP_Depend>=1.1.0:../../wip/pear-PHP_Depend
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
