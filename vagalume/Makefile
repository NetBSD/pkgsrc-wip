# $NetBSD: Makefile,v 1.5 2010/01/17 12:03:33 thomasklausner Exp $
#

DISTNAME=	vagalume_${VERSION}.orig
PKGNAME=	vagalume-${VERSION}
VERSION=	0.7.1
PKGREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://vagalume.igalia.com/files/source/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://vagalume.igalia.com/
COMMENT=	GTK+-based Last.fm client
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/vagalume-${VERSION}.orig
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt pkg-config

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
