# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=	libslab-2.30.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/libslab/2.30/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/libslab/
COMMENT=	Slab memory allocator in application layer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	libslab.pc.in

.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
