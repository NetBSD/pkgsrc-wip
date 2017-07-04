# $NetBSD$
libfpx_ver=	1.3.1
DISTNAME=	libfpx-${libfpx_ver}-8
PKGNAME=	libfpx-${libfpx_ver}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.imagemagick.org/pub/ImageMagick/delegates/ \
		ftp://ftp.kddlabs.co.jp/graphics/ImageMagick/delegates/ \
		http://www.imagemagick.org/download/delegates/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.imagemagick.org/
COMMENT=	Library for reading FlashPix images
LICENSE=	zlib AND original-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/flashpix.h \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/copyright-notice

.include "../../mk/bsd.pkg.mk"
