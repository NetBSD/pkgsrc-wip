# $NetBSD: Makefile,v 1.1 2013/07/15 20:14:21 thomasklausner Exp $

DISTNAME=	cairo-dock-3.2.1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/cairo-dock-core/3.2/3.2.1/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.glx-dock.org/
COMMENT=	Dock application
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}

PKGCONFIG_OVERRIDE=	src/gldit/gldi.pc.in cairo-dock.pc.in

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
