# $NetBSD: Makefile,v 1.3 2006/01/08 03:00:18 minskim Exp $
#

PKGNAME=		ruby-gnome2-libart-${VERSION}
COMMENT=		Ruby binding of Libart_lgpl
CATEGORIES=		graphics

RUBY_EXTCONF_SUBDIRS=	libart

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
