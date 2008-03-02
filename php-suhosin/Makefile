# $NetBSD: Makefile,v 1.7 2008/03/02 00:37:01 hoka_adam Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.23
CATEGORIES=		www
MASTER_SITES=		http://download.suhosin.org/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.hardened-php.net/suhosin/index.html
COMMENT=		Advanced protection system for PHP installations

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
