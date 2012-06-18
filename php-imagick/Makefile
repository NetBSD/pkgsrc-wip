# $NetBSD: Makefile,v 1.3 2012/06/18 23:57:38 kaosagnt Exp $

MODNAME=		imagick
PECL_VERSION=		3.1.0RC2
CATEGORIES+=		graphics www

#MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		php-imagick-[0-9]*

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
