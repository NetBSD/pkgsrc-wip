# $NetBSD: Makefile,v 1.4 2010/05/01 22:14:05 thomasklausner Exp $

DISTNAME=	tracker-0.6.6
PKGNAME=	meta-tracker-0.6.6
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.gnome.org/~jamiemcc/tracker/
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

PKGCONFIG_OVERRIDE+=	libtracker-gtk.pc.in
PKGCONFIG_OVERRIDE+=	tracker.pc.in

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
.include "../../mail/gmime/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.4.3
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
