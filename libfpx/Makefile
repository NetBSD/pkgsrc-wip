# $NetBSD$
libfpx_ver=	1.3.1
DISTNAME=	libfpx-${libfpx_ver}-4
PKGNAME=	libfpx-${libfpx_ver}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.imagemagick.org/pub/ImageMagick/delegates/ \
		ftp://ftp.kddlabs.co.jp/graphics/ImageMagick/ \
		http://www.imagemagick.org/download/delegates/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.imagemagick.org/
COMMENT=	Library for reading FlashPix images
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	autoconf
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.pkg.mk"
