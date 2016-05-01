# $NetBSD: Makefile,v 1.6 2015/04/10 19:06:32 krytarowski Exp $

USE_GTK_VERSION=2
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2

.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Allow applications to export a menu into the panel

.include "../../wip/libindicator/buildlink3.mk"
.include "../../wip/libdbusmenu-gtk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
