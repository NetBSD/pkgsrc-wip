# $NetBSD: Makefile,v 1.5 2015/07/07 18:50:58 leot1990 Exp $

DISTNAME=	zbar-0.10
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zbar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://zbar.sourceforge.net/
COMMENT=	Bar code reader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++	# c++ needed only for test

# XXX: should we move some of them to options.mk?
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--disable-video
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-qt

# pkgsrc ImageMagick always provide also <MagickWand.h> there is no need
# to check it also manually (and this breaks with ImageMagick-7)
CONFIGURE_ENV+=		ac_cv_header_wand_MagickWand_h=yes

PKGCONFIG_OVERRIDE+=	zbar-gtk.pc.in
PKGCONFIG_OVERRIDE+=	zbar-qt.pc.in
PKGCONFIG_OVERRIDE+=	zbar.pc.in

TEST_TARGET=	check

REPLACE_PYTHON+=		test/barcodetest.py
PYTHON_FOR_BUILD_ONLY=		test
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../lang/python/application.mk"

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
