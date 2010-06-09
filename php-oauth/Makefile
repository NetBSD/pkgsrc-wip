# $NetBSD: Makefile,v 1.3 2010/06/09 11:58:59 fhajny Exp $

MODNAME=		oauth
PECL_VERSION=		1.0.0
CATEGORIES+=		security

MAINTAINER=		filip@joyent.com
COMMENT=		PHP oauth consumer extension
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
