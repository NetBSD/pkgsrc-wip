# $NetBSD: Makefile,v 1.3 2006/01/08 03:00:17 minskim Exp $
#

PKGNAME=		ruby-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
