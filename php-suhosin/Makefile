# $NetBSD: Makefile,v 1.9 2012/10/05 11:12:56 asau Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.27
CATEGORIES=		www
MASTER_SITES=		http://download.suhosin.org/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.hardened-php.net/suhosin/index.html
COMMENT=		Advanced protection system for PHP installations

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
