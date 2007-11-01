# $NetBSD: Makefile,v 1.5 2007/11/01 18:44:00 rumko Exp $
#

MODNAME=	suhosin
DISTNAME=	suhosin-${PECL_VERSION}
PECL_VERSION=	0.9.20
CATEGORIES=	www
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://www.hardened-php.net/suhosin/index.html
COMMENT=	Advanced protection system for PHP installations

CONFIGURE_ARGS=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
