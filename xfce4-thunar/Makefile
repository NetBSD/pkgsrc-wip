# $NetBSD: Makefile,v 1.25 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

THUNAR_VERSION=	1.3.0

DISTNAME=	Thunar-${THUNAR_VERSION}
PKGNAME=	xfce4-thunar-${THUNAR_VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
COMMENT=	Xfce file manager

XFCE4_PROJECT=  thunar
XFCE4_BRANCH=   1.3

#PKGCONFIG_OVERRIDE+=	thunar-vfs/thunar-vfs-1.pc.in
PKGCONFIG_OVERRIDE+=	thunarx/thunarx-2.pc.in

PKG_SYSCONFSUBDIR=	xdg
EGDIR=			${XFCE4_EGBASE}/Thunar

#MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
#MAKE_DIRS+=	${XFCE4_EGBASE} ${PREFIX}/share/xfce4
#MAKE_DIRS+=	${PREFIX}/share/xfce4/panel-plugins
MAKE_DIRS+=		${PKG_SYSCONFDIR}/Thunar

CONF_FILES=	${EGDIR}/uca.xml ${PKG_SYSCONFDIR}/Thunar/uca.xml

#.include "options.mk"

DEPENDS+=	gio-fam:../../sysutils/gio-fam
DEPENDS+=	gvfs:../../sysutils/gvfs

#.include "../../devel/GConf/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
#.include "../../wip/libxfce4util/buildlink3.mk"
#.include "../../x11/startup-notification/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
#.include "../../mk/fam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
