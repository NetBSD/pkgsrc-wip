# $NetBSD: Makefile,v 1.2 2010/10/06 09:36:39 fhajny Exp $

MODNAME=		intl
PECL_VERSION=		1.1.1
CATEGORIES+=		devel

MAINTAINER=		filip@joyent.com
COMMENT=		Internationalization extension implements ICU library functionality

PKG_DESTDIR_SUPPORT=	user-destdir

PHP_VERSIONS_ACCEPTED=	52
CONFLICTS=		php-intl-[0-9]*

USE_LANGUAGES=		c c++

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
