# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-gnomecanvas-${VERSION}
COMMENT=		Ruby binding of GnomeCanvas-2.x
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	gnomecanvas

DEPENDS+=		ruby-gnome2-libart>=${VERSION}:../../wip/ruby-gnome2-libart
DEPENDS+=		ruby-gnome2-gtk>=${VERSION}:../../wip/ruby-gnome2-gtk

USE_TOOLS+=		pkg-config

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../wip/ruby-gnome2/Makefile.common"
