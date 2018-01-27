# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gimmie-0.2.8
PKGREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	http://www.beatniksoftware.com/gimmie/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beatniksoftware.com/gimmie/
COMMENT=	Creative panel replacement

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LANGUAGES=		c c++

PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2, py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsexy+=	libsexy>=0.1.8
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomecups+=	libgnomecups>=0.2.0
.include "../../print/libgnomecups/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
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
