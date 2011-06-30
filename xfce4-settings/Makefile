# $NetBSD: Makefile,v 1.1 2011/06/30 20:47:40 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

SETTINGS_VERSION=	4.8.2

DISTNAME=		xfce4-settings-${SETTINGS_VERSION}
#PKGREVISION=		1
CATEGORIES=		x11
COMMENT=		Xfce settings manager

# There is a 4.9 around, usable?
XFCE4_PROJECT=  	xfce4-settings
XFCE4_BRANCH=		4.8

BUILD_DEFS+=		PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

EGDIR=			${XFCE4_EGBASE}/xfconf/xfce-perchannel-xml
PKG_SYSCONFSUBDIR=	xdg

MAKE_DIRS+=	${XFCE4_EGBASE:Q} ${XFCE4_EGBASE:Q}/xfconf ${EGDIR}

CONF_FILES=	${EGDIR}/xsettings.xml \
	${PKG_SYSCONFDIR}/xfce4/xfconf/xfce-perchannel-xml/xsettings.xml

CONF_FILES+=	\
	${XFCE4_EGBASE:Q}/autostart/xfce4-settings-helper-autostart.desktop \
	${PKG_SYSCONFDIR}/autostart/xfce4-settings-helper-autostart.desktop

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../wip/xfconf/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../wip/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
