# $NetBSD: Makefile,v 1.1.1.1 2009/10/14 08:23:39 fhajny Exp $

MODNAME=		oauth
PECL_VERSION=		0.99.9
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
