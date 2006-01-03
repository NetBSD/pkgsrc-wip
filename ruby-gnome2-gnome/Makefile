# $NetBSD: Makefile,v 1.1.1.1 2006/01/03 14:36:41 roelants Exp $
#

PKGNAME=		ruby-gnome2-gnome-${VERSION}
COMMENT=		Ruby binding of libgnome/libgnomeui-2.x

RUBY_EXTCONF_SUBDIRS=	gnome

DEPENDS+=		ruby-gnome2-gnomecanvas>=${VERSION}:../../wip/ruby-gnome2-gnomecanvas

USE_TOOLS+=		pkg-config

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../wip/ruby-gnome2-all/Makefile.common"
