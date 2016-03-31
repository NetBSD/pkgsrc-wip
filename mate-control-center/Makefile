# $NetBSD: Makefile,v 1.7 2015/04/09 20:38:31 krytarowski Exp $

DISTNAME=	mate-control-center-1.12.1
CATEGORIES=	sysutils
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/releases/
COMMENT=	MATE Control Center
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	capplets/keybindings/mate-keybindings.pc.in
PKGCONFIG_OVERRIDE+=	capplets/default-applications/mate-default-applications.pc.in
PKGCONFIG_OVERRIDE+=	libslab/libslab.pc.in
PKGCONFIG_OVERRIDE+=	libwindow-settings/mate-window-settings-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/menus/matecc.menu \
		${PKG_SYSCONFDIR}/xdg/menus/matecc.menu

.include "../../devel/glib2/schemas.mk"

.include "../../wip/libappindicator/buildlink3.mk"
.include "../../wip/libmatekbd/buildlink3.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-menus/buildlink3.mk"
.include "../../wip/marco/buildlink3.mk"
.include "../../wip/mate-settings-daemon/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
