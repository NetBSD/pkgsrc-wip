# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:30 thomasklausner Exp $

MODNAME=		oauth
PKGREVISION=		1
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
