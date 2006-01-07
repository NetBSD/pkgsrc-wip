# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:42 roelants Exp $
#

PKGNAME=		ruby-gnome2-gtk-${VERSION}
COMMENT=		Ruby binding of GTK+-2.0.x
CATEGORIES=		x11

RUBY_EXTCONF_SUBDIRS=	gtk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
DEPENDS+=		ruby-gnome2-atk>=${VERSION}:../../wip/ruby-gnome2-atk
DEPENDS+=		ruby-gnome2-gdkpixbuf>=${VERSION}:../../wip/ruby-gnome2-gdkpixbuf

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ruby-gnome2-pango/buildlink3.mk"
.include "../../wip/ruby-gnome2/Makefile.common"
