# $NetBSD: Makefile,v 1.15 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=	tracker-1.7.3
PKGNAME=	meta-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker/0.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://projects.gnome.org/tracker/
COMMENT=	Extract information and metadata about your personal data
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_TOOLS+=		msgfmt
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
# tracker_miner_fs-tracker-power-hal.o: In function `tracker_power_init':
# tracker-power-hal.c:(.text+0x447): undefined reference to `dbus_connection_setup_with_g_main'
LDFLAGS+=		-ldbus-glib-1

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	data/tracker-sparql.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-miner.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-client.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-extract.pc.in

#TRACKER_VERSION= ${PKGVERSION:C/\.[0-9]+$//}
# strip last .digit (but not safe if it is missing)
PLIST_SUBST+=	TRACKER_VERSION=tracker-${PKGVERSION_NOREV:C/\.[0-9]+$//}

.include "options.mk"

#PKGCONFIG_OVERRIDE+=	dbus-glib-1.pc.in

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"	# XXX maybe optional

.include "../../mk/bsd.pkg.mk"
