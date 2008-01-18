# $NetBSD: Makefile,v 1.3 2008/01/18 04:30:13 tnn2 Exp $
#

DISTNAME=	gimmie-0.2.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.beatniksoftware.com/gimmie/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://beatnik.infogami.com/Gimmie
COMMENT=	Creative panel replacement

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
PY_PATCHPLIST=	yes
USE_TOOLS+=	gmake intltool pkg-config

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../print/libgnomecups/buildlink3.mk"
.include "../../sysutils/py-gnome-menus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
