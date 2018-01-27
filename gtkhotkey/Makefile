# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:36 thomasklausner Exp $
#

DISTNAME=	gtkhotkey-0.2.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/gtkhotkey/0.2/0.2.1/+download/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/gtkhotkey/
COMMENT=	GtkHotkey library Platform independent hotkey handling for Gtk+
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool msgfmt perl
USE_LANGUAGES+=		c c++

PKGCONFIG_OVERRIDE+=	gtkhotkey-1.0.pc.in

INSTALLATION_DIRS=	lib

#BUILDLINK_API_DEPENDS.glib2+=    glib2 >=2.10.6
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
