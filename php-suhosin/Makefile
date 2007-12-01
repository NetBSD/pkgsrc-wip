# $NetBSD: Makefile,v 1.6 2007/12/01 23:21:03 hoka_adam Exp $
#

MODNAME=	suhosin
DISTNAME=	suhosin-${PECL_VERSION}
PECL_VERSION=	0.9.22
CATEGORIES=	www
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://www.hardened-php.net/suhosin/index.html
COMMENT=	Advanced protection system for PHP installations

CONFIGURE_ARGS=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
