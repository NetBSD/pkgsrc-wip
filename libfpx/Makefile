# $NetBSD$
libfpx_ver=	1.3.1
DISTNAME=	libfpx-${libfpx_ver}-9
PKGNAME=	libfpx-${libfpx_ver}
PKGREVISION=	4
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

docdir=		 share/doc/${PKGBASE}
INSTALLATION_DIRS+=${docdir}
post-install:
	${INSTALL_DATA} ${WRKSRC}/flashpix.h \
		${DESTDIR}${PREFIX}/${docdir}/copyright-notice
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${DESTDIR}${PREFIX}/${docdir}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.txt \
		${DESTDIR}${PREFIX}/${docdir}

.include "../../mk/bsd.pkg.mk"
