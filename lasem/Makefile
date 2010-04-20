# $NetBSD: Makefile,v 1.1.1.1 2010/04/20 20:12:00 jihbed Exp $
#

DISTNAME=	lasem-0.2.0
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/lasem/0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/lasem/0.2/
COMMENT=	Lasem is a library for rendering SVG and Mathml
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config bison intltool flex gmake

PKGCONFIG_OVERRIDE+=	lasem.pc.in

.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.6.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.0.0nb2
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
