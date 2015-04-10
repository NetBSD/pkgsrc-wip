# $NetBSD: Makefile,v 1.1 2015/04/10 18:33:03 krytarowski Exp $

DISTNAME=	libappindicator-12.10.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libappindicator/12.10/12.10.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libappindicator/
COMMENT=	Allow applications to export a menu into the panel
LICENSE=	gnu-lgpl-v3 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

EXTRACT_USING=	gtar

PKGCONFIG_OVERRIDE+=	bindings/mono/appindicator-sharp-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator3-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator-0.1.pc.in

.include "../../wip/libindicator/buildlink3.mk"
.include "../../wip/libdbusmenu-gtk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
