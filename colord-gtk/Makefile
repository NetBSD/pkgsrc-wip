# $NetBSD$

DISTNAME=	colord-gtk-0.1.26
CATEGORIES=	graphics
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Manage color profiles to accurately color input/output devices
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

PKGCONFIG_OVERRIDE+=	libcolord-gtk/colord-gtk2.pc.in
PKGCONFIG_OVERRIDE+=	libcolord-gtk/colord-gtk.pc.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../wip/colord/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
