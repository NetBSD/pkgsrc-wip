# $NetBSD: Makefile,v 1.4 2012/03/25 18:56:31 fhajny Exp $

MODNAME=		oauth
PECL_VERSION=		1.2.2
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
