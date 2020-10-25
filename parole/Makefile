# $NetBSD$

DISTNAME=       parole-${VERS}
VERS=		1.0.5
CATEGORIES=     multimedia
MASTER_SITES=	https://archive.xfce.org/src/apps/parole/1.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.xfce.org/apps/parole/start
COMMENT=	Simple media player based on the GStreamer framework
LICENSE=	gnu-gpl-v2

USE_TOOLS+=             gmake pkg-config intltool
USE_LIBTOOL=            yes
USE_LANGUAGES=          c c++
HAS_CONFIGURE=          yes
CONFIGURE_ARGS+=        --prefix=${PREFIX}

PKG_OPTIONS_VAR=        PKG_OPTIONS.parole
PKG_SUPPORTED_OPTIONS=  libnotify
PLIST_VARS+=            notify

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
PLIST.notify=   yes
.else
CONFIGURE_ARGS+=        --disable-notify-plugin
.endif

.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
