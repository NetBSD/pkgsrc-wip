# $NetBSD: Makefile,v 1.12 2008/10/29 10:49:20 thomasklausner Exp $
#

DISTNAME=	muine-0.8.10
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/muine/0.8/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://muine-player.org/wiki/Main_Page
COMMENT=	Simple and intuitive music player for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool pkg-config

GCONF_SCHEMAS=		muine.schemas

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../audio/flac/buildlink3.mk"
# wants mp4ff.h, which is not in our faad2 package
#.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../lang/monodoc/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
