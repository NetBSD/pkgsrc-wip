# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 14:32:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../wip/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

.include "../../devel/pango/buildlink3.mk"
.include "../../wip/ruby-gnome2-all/Makefile.common"
