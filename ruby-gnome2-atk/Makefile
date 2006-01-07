# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../wip/ruby-gnome2/Makefile.common"
