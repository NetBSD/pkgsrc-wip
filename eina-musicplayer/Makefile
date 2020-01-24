# $NetBSD: Makefile,v 1.1 2014/02/17 10:45:35 thomasklausner Exp $

DISTNAME=	eina-0.14.0
PKGNAME=	${DISTNAME:S/eina/eina-musicplayer/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://launchpad.net/eina/trunk/0.14.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://eina.sourceforge.net/
COMMENT=	Traditional audio player with a GTK2 interface
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c99
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt msgmerge perl pkg-config xgettext

PKGCONFIG_OVERRIDE+=	data/eina-0.14.pc.in
PKGCONFIG_OVERRIDE+=	data/gel-2.0.pc.in
PKGCONFIG_OVERRIDE+=	data/gel-ui-2.0.pc.in
PKGCONFIG_OVERRIDE+=	data/lomo-2.0.pc.in

REPLACE_PYTHON=		eina/lastfm/lastfmsubmitd/lastfmsubmitd

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
# XXX Needs clutter-gtk-1.0
# XXX which needs a new version of clutter
# XXX which needs cogl which is currently broken
#.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
