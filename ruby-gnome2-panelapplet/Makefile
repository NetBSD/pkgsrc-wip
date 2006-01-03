# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 14:42:44 roelants Exp $
#

PKGNAME=		ruby-gnome2-panelapplet-${VERSION}
COMMENT=		Ruby binding of libpanel-applet-2.6.x

RUBY_EXTCONF_SUBDIRS=	panel-applet

DEPENDS+=		ruby-gnome2-gnome>=${VERSION}:../../wip/ruby-gnome2-gnome

USE_TOOLS+=		pkg-config

.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../wip/ruby-gnome2-all/Makefile.common"
