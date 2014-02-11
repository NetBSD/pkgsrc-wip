# $NetBSD: Makefile,v 1.3 2014/02/11 21:04:08 noud4 Exp $

DISTNAME=	banshee-2.6.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/banshee/2.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://banshee.fm/
COMMENT=	Media player
LICENSE=	mit

GNU_CONFIGURE=		yes

USE_TOOLS+=		intltool pkg-config gmake gsed msgfmt
USE_TOOLS+=		bash:run
REPLACE_BASH+=		src/Clients/Booter/banshee.linux.in \
			src/Extensions/Banshee.AmazonMp3/bamz.in
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-collection-indexer.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-core.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-hyena-data-sqlite.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-hyena-gui.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-hyena.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-lastfm-gui.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-lastfm.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-mono-media.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-musicbrainz.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-nowplaying.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-services.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-thickclient.pc.in
PKGCONFIG_OVERRIDE+=	build/pkg-config/banshee-webbrowser.pc.in

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../sysutils/dbus-sharp-glib//buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/mono-zeroconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.taglib-sharp+=	taglib-sharp>=2.0.3.7
.include "../../wip/taglib-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
