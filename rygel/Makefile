# $NetBSD: Makefile,v 1.3 2015/06/07 14:24:49 yrmt Exp $
#

DISTNAME=	rygel-0.16.3
CATEGORIES=	net audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/rygel/0.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://live.gnome.org/Rygel
COMMENT=	UPnP AV MediaServer that allows sharing audio, video, and pictures
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

PKGCONFIG_OVERRIDE+=	rygel-core-1.0.pc.in
PKGCONFIG_OVERRIDE+=	rygel-renderer-1.0.pc.in
PKGCONFIG_OVERRIDE+=	rygel-server-1.0.pc.in

CONFIGURE_ARGS+=	--disable-tracker-plugin

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
# conflicts with net/gupnp/buildlink3.mk
#.include "../../devel/libuuid/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../net/gupnp/buildlink3.mk"
.include "../../net/gupnp-av/buildlink3.mk"
.include "../../net/gupnp-dlna/buildlink3.mk"
#gone from pkgsrc? .include "../../net/gupnp-vala/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
