# $NetBSD: Makefile,v 1.5 2014/12/24 05:08:48 obache Exp $

DISTNAME=	libslab-2.30.0
PKGREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/libslab/2.30/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/libslab/
COMMENT=	Slab memory allocator in application layer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	libslab.pc.in

.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.18.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../wip/gnome-desktop2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
