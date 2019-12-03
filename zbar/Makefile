# $NetBSD: Makefile,v 1.5 2015/07/07 18:50:58 leot1990 Exp $

DISTNAME=	zbar-0.23
CATEGORIES=	graphics
MASTER_SITES=	https://linuxtv.org/downloads/zbar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://zbar.sourceforge.net/
COMMENT=	Bar code reader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++	# c++ needed only for test

CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--disable-video
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-qt

PKGCONFIG_OVERRIDE+=	zbar-gtk.pc.in
PKGCONFIG_OVERRIDE+=	zbar-qt.pc.in
PKGCONFIG_OVERRIDE+=	zbar.pc.in

TEST_TARGET=	check

# Examples and tests require python
# XXX: use big hammer to forcely disable python
#REPLACE_PYTHON+=		test/barcodetest.py examples/upcrpc.py
#PYTHON_FOR_BUILD_ONLY=		test
#PYTHON_VERSIONS_ACCEPTED=	27	# tests not ported to Python 3?
#.include "../../lang/python/application.mk"

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
