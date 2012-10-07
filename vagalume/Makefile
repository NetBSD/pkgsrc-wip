# $NetBSD: Makefile,v 1.8 2012/10/07 17:41:40 asau Exp $
#

DISTNAME=	vagalume-0.8.5
CATEGORIES=	audio net
MASTER_SITES=	http://vagalume.igalia.com/files/source/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://vagalume.igalia.com/
COMMENT=	GTK+-based Last.fm client
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.4.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
