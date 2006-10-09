# $NetBSD: Makefile,v 1.1 2006/10/09 11:34:44 christian_gall Exp $
#

MODNAME=	suhosin
DISTNAME=	suhosin-0.9.8
PECL_VERSION=	0.9.8
CATEGORIES=	www
MASTER_SITES=	http://www.hardened-php.net/suhosin/_media/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cg@cgall.de
HOMEPAGE=	http://www.hardened-php.net/suhosin/index.html
COMMENT=	Advanced protection system for PHP installations

CONFIGURE_ARGS=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
