# $NetBSD: Makefile,v 1.1.1.1 2009/10/08 11:49:54 fhajny Exp $

MODNAME=		intl
PECL_VERSION=		1.0.2
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
COMMENT=		Internationalization extension implements ICU library functionality

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-intl-[0-9]*

USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
