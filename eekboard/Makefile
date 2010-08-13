# $NetBSD: Makefile,v 1.2 2010/08/13 02:15:21 obache Exp $
#

DISTNAME=	eekboard-0.0.5
CATEGORIES=	x11
MASTER_SITES=	http://github.com/downloads/ueno/eekboard/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ueno.github.com/eekboard/
COMMENT=	Virtual keyboard for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool

PKGCONFIG_OVERRIDE+=	eek/eek-xkl-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-xkb-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-clutter-0.1.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-gtk-0.1.pc.in

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../wip/libfakekey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
