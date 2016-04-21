# $NetBSD: Makefile,v 1.7 2015/04/09 20:38:31 krytarowski Exp $

.include "../../wip/mate/Makefile.common"

DISTNAME=	mate-desktop-${MATE_VERSION}
CATEGORIES=	x11

COMMENT=	MATE desktop library

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	libmate-desktop/mate-desktop-2.0.pc.in

REPLACE_SH+=	tools/mate-gsettings-toggle

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
