# $NetBSD: Makefile,v 1.2 2015/07/13 09:06:07 thomasklausner Exp $

DISTNAME=	cairo-dock-3.4.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cairo-Dock/}
GITHUB_PROJECT=	cairo-dock-core

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.glx-dock.org/
COMMENT=	Dock application
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}

WRKSRC=		${WRKDIR}/cairo-dock-core-3.4.1

PKGCONFIG_OVERRIDE=	src/gldit/gldi.pc.in cairo-dock.pc.in
REPLACE_SH+=		data/scripts/initial-setup.sh
REPLACE_SH+=		data/scripts/cairo-dock-package-theme.sh
REPLACE_SH+=		data/scripts/help_scripts.sh

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
