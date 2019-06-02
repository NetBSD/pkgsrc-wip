# $NetBSD$

DISTNAME=	parole-${VERS}
CATEGORIES=	multimedia
MASTER_SITES=	https://archive.be.xfce.org/src/apps/parole/1.0/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.xfce.org/apps/parole/start
COMMENT=	Simple media player based on the GStreamer framework
LICENSE=        gnu-gpl-v2
VERS=		1.0.2
EXTRACT_SUFX=   .tar.bz2

USE_TOOLS+=	gmake pkg-config intltool
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}

PKG_OPTIONS_VAR=	PKG_OPTIONS.parole
PKG_SUPPORTED_OPTIONS=	x11 oss alsa libav libnotify tray mpris2
PKG_SUGGESTED_OPTIONS=	x11 oss

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mx11)
DEPENDS=gst-plugins1-x11-[0-9]*:../../x11/gst-plugins1-x11
.endif

.if empty(PKG_OPTIONS:Moss)
DEPENDS=gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.endif

.if empty(PKG_OPTIONS:Malsa)
DEPENDS=gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.endif

.if empty(PKG_OPTIONS:Mlibav)
DEPENDS=gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
.endif

.if !empty(PKG_OPTIONS:Mlibnotify)
.include "../../sysutils/libnotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-notify-plugin
.endif

.if empty(PKG_OPTIONS:Mtray)
CONFIGURE_ARGS+=	--disable-tray-plugin
.endif

.if empty(PKG_OPTIONS:Mmpris2)
CONFIGURE_ARGS+=	--disable-mpris2-plugin
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
