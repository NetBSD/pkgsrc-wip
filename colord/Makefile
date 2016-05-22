# $NetBSD$

DISTNAME=	colord-1.2.12
CATEGORIES=	graphics gnome
MASTER_SITES=	https://www.freedesktop.org/software/colord/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/software/colord/
COMMENT=	Device color profile management daemon
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in

CONFIGURE_ARGS+=	--enable-gusb=no
CONFIGURE_ARGS+=	--disable-rfkill
CONFIGURE_ARGS+=	--disable-network-manager
CONFIGURE_ARGS+=	--enable-udev=no

# Seems badly detected
CONFIGURE_ARGS+=	--disable-bash-completion

CONFIGURE_ARGS+=	--disable-systemd-login

PKGCONFIG_OVERRIDE+=	lib/colorhug/colorhug.pc.in
PKGCONFIG_OVERRIDE+=	lib/colord/colord.pc.in


# XXX conf file?
#CONF_FILES+=		data/org.freedesktop.ColorManager.conf

# XXX maybe make wip/argyllcms work instead?
CONFIGURE_ARGS += --disable-argyllcms-sensor
#.include "../../wip/argyllcms/buildlink3.mk"

.include "../../print/cups/buildlink3.mk"
.include "../../wip/geocode-glib/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../devel/libdbusmenu-qt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
