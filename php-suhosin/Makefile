# $NetBSD: Makefile,v 1.2 2006/11/22 13:09:00 christian_gall Exp $
#

MODNAME=	suhosin
DISTNAME=	suhosin-0.9.14
PECL_VERSION=	0.9.14
CATEGORIES=	www
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://www.hardened-php.net/suhosin/index.html
COMMENT=	Advanced protection system for PHP installations

CONFIGURE_ARGS=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
