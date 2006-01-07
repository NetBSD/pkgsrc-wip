# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-gdkpixbuf-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		devel graphics

RUBY_EXTCONF_SUBDIRS=	gdkpixbuf

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/ruby-gnome2/Makefile.common"
