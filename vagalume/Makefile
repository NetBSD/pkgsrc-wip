# $NetBSD: Makefile,v 1.1.1.1 2008/11/02 19:43:04 roelants Exp $
#

DISTNAME=	vagalume_${VERSION}.orig
PKGNAME=	vagalume-${VERSION}
VERSION=	0.7
CATEGORIES=	audio net
MASTER_SITES=	http://vagalume.igalia.com/files/source/

MAINTAINER=	dieter.NetBSD@pandora.be
HOMEPAGE=	http://vagalume.igalia.com/
COMMENT=	GTK+-based Last.fm client

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
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
