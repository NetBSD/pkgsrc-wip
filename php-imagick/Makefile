# $NetBSD: Makefile,v 1.1.1.1 2011/07/10 10:50:31 anthony_mallet Exp $

MODNAME=		imagick
PECL_VERSION=		3.0.1
CATEGORIES+=		graphics www

#MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		php-imagick-[0-9]*

USE_LANGUAGES=		c c++
CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_DIR:Q}

USE_PHP_EXT_PATCHES=	yes

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
