# $NetBSD: Makefile,v 1.2 2014/08/03 22:16:38 thomasklausner Exp $

DISTNAME=	cairo-dock-plugins-3.2.1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/cairo-dock-plug-ins/3.2/3.2.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.glx-dock.org/
COMMENT=	Dock application plugins
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mail/libetpan/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/cairo-dock/buildlink3.mk"
.include "../../devel/libindicator3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
