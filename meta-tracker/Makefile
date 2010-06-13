# $NetBSD: Makefile,v 1.6 2010/06/13 22:47:11 thomasklausner Exp $

DISTNAME=	tracker-0.6.96
PKGNAME=	meta-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/tracker/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/tracker/
COMMENT=	Extract information and metadata about your personal data
LICENSE=	gnu-gpl-v2

DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	data/tracker.pc.in
PKGCONFIG_OVERRIDE+=	data/tracker-module-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/libtracker-gtk.pc.in

.include "options.mk"

.include "../../databases/qdbm/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/exempi/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/hal/buildlink3.mk"
BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.4.3
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
