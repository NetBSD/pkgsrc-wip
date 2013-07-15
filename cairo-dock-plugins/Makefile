# $NetBSD: Makefile,v 1.1 2013/07/15 20:27:37 thomasklausner Exp $

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


.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mail/libetpan/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/cairo-dock/buildlink3.mk"
.include "../../wip/libindicator/buildlink3.mk"
#-- WARNING: It seems that one (or more) module(s) is (are) missing: indicator(-0.4) (libido-0.1) dbusmenu-glib(-0.4) dbusmenu-gtk(-0.4) alsa libical libgnome-menu-3.0 libpulse upower-glib zeitgeist-1.0 alsa
#-- It can be interesting to install them (especially if you're a maintainer of Cairo-Dock's packages).
#-- WARNING: It seems that one (or more) program(s) or package(s) is (are) missing: ruby valac sensors
#-- It can be interesting to install them (especially if you're a maintainer of Cairo-Dock's packages).
.include "../../mk/bsd.pkg.mk"
