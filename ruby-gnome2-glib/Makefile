# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/ruby-gnome2/Makefile.common"
