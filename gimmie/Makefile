# $NetBSD: Makefile,v 1.4 2009/03/12 11:15:32 thomasklausner Exp $
#

DISTNAME=	gimmie-0.2.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.beatniksoftware.com/gimmie/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beatniksoftware.com/gimmie
COMMENT=	Creative panel replacement

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DIRS=	gnome2-1.6 xdg-1.4
USE_LIBTOOL=	yes
PY_PATCHPLIST=	yes
USE_TOOLS+=	gmake intltool pkg-config

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/libgnomecups/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnome-menus+=	gnome-menus>=2.18
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/py-gnome-menus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
