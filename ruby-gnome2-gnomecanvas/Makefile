# $NetBSD: Makefile,v 1.3 2006/01/08 03:00:18 minskim Exp $
#

PKGNAME=		ruby-gnome2-gnomecanvas-${VERSION}
COMMENT=		Ruby binding of GnomeCanvas-2.x
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	gnomecanvas

DEPENDS+=		ruby-gnome2-libart>=${VERSION}:../../wip/ruby-gnome2-libart
DEPENDS+=		ruby-gnome2-gtk>=${VERSION}:../../wip/ruby-gnome2-gtk

USE_TOOLS+=		pkg-config

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
