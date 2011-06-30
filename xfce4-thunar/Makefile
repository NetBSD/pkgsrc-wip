# $NetBSD: Makefile,v 1.17 2011/06/30 10:24:50 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

THUNAR_VERSION=	1.3.0

DISTNAME=	Thunar-${THUNAR_VERSION}
PKGNAME=	xfce4-thunar-${THUNAR_VERSION}
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

#PKG_FAIL_REASON+="It still crashes, might be an exo problem"

#.include "options.mk"

#.include "../../devel/GConf/buildlink3.mk"
#.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
#.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
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
