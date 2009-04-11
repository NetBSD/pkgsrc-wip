# $NetBSD: Makefile,v 1.3 2009/04/11 22:01:21 jihbed Exp $
#

DISTNAME=	dragbox-0.4.0
CATEGORIES=	misc gnome
MASTER_SITES=	http://kaizer.se/publicfiles/dragbox/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://users.student.lth.se/f04us/wiki/dragbox/
COMMENT=	Command line drag-and-drop tool for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

REPLACE_PYTHON+=	dragbox
PY_PATCHPLIST=	yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
