# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 14:30:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../wip/ruby-gnome2-all/Makefile.common"
