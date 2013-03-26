# $NetBSD: Makefile,v 1.5 2013/03/26 12:45:45 fhajny Exp $

MODNAME=		imagick
PECL_VERSION=		3.1.0RC2
CATEGORIES+=		graphics www

#MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

CONFLICTS=		php-imagick-[0-9]*

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
