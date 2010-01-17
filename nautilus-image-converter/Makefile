# $NetBSD: Makefile,v 1.3 2010/01/17 12:03:29 thomasklausner Exp $
#

DISTNAME=	nautilus-image-converter-0.3.0
PKGREVISION=	1
CATEGORIES=	sysutils graphics gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/nautilus-image-converter/0.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.bitron.ch/software/nautilus-image-converter.php
COMMENT=	Nautilus extension to mass resize or rotate images

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl intltool gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
