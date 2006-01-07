# $NetBSD: Makefile,v 1.2 2006/01/07 17:55:42 roelants Exp $
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
.include "../../wip/ruby-gnome2/Makefile.common"
