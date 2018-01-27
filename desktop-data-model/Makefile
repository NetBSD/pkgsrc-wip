# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:35 asau Exp $
#

DISTNAME=	desktop-data-model-1.2.5
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/desktop-data-model/1.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://ftp.gnome.org/pub/GNOME/sources/desktop-data-model
COMMENT=	Engine providing live updates of online data to the desktop
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ddm-1.pc.in

CONFIGURE_ARGS+=	--without-empathy
CONFIGURE_ARGS+=	--with-maemo=no


TEST_TARGET=	build

BUILDLINK_API_DEPENDS.loudmouth+=	loudmouth>=1.0
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
