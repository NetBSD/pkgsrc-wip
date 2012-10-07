# $NetBSD: Makefile,v 1.14 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

XFWM_VER=	4.8.3

DISTNAME=	xfwm4-${XFWM_VER}
PKGNAME=	xfce4-wm-${XFWM_VER}
#PKGREVISION=	1
CATEGORIES=	wm
COMMENT=	Xfce window manager

XFCE4_PROJECT=  	xfwm4
XFCE4_BRANCH=		4.8

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/share/themes/Default
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/fr/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/it ${PREFIX}/share/xfce4/doc/it/images

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
