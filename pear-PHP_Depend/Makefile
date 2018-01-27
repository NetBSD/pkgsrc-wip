# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:09 noud4 Exp $
#

DISTNAME=	PHP_Depend-1.1.0
CATEGORIES=	devel
MASTER_SITES+=	http://pear.pdepend.org/get/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://pdepend.org/
COMMENT=	PHP_Depend design quality metrics for PHP packages	
LICENSE=	original-bsd

BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-pear-channel-pdepend-[0-9]*:../../wip/pear-channel-pdepend
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

# XXX option pecl/imagick

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
