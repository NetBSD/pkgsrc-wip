# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:35 asau Exp $
#

DISTNAME=	lasem-0.2.0
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/lasem/0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	ftp://ftp.gnome.org/pub/gnome/sources/lasem/0.2/
COMMENT=	Lasem is a library for rendering SVG and Mathml
LICENSE=	gnu-gpl-v2

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
