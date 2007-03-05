# $NetBSD: Makefile,v 1.3 2007/03/05 01:59:41 christian_gall Exp $
#

MODNAME=	suhosin
DISTNAME=	suhosin-${PECL_VERSION}
PECL_VERSION=	0.9.17
CATEGORIES=	www
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://www.hardened-php.net/suhosin/index.html
COMMENT=	Advanced protection system for PHP installations

CONFIGURE_ARGS=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
