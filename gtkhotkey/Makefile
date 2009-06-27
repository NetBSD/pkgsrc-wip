# $NetBSD: Makefile,v 1.3 2009/06/27 00:06:02 jihbed Exp $
#

DISTNAME=	gtkhotkey-0.2.0
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/gtkhotkey/0.2/0.2.0/+download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/gtkhotkey/
COMMENT=	GtkHotkey library Platform independent hotkey handling for Gtk+
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=    user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR= yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt perl
USE_LANGUAGES+=	c c++


PKGCONFIG_OVERRIDE+=	gtkhotkey-1.0.pc.in

#BUILDLINK_API_DEPENDS.glib2+=    glib2 >=2.10.6
BUILDLINK_API_DEPENDS.gtk2+=    gtk2+>=2.12.0

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
