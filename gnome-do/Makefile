# $NetBSD: Makefile,v 1.6 2012/01/10 14:21:29 thomasklausner Exp $
#

DISTNAME=	gnome-do-0.8.5
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/do/trunk/0.8.5/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://do.davebsd.com/
COMMENT=	Panel replacement
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

# has too long file names
EXTRACT_USING=	gtar

GCONF_SCHEMAS+=	gnome-do.schemas

PKGCONFIG_OVERRIDE+=	Do.Platform/do.platform.pc.in
PKGCONFIG_OVERRIDE+=	Do.Platform.Linux/do.platform.linux.pc.in
PKGCONFIG_OVERRIDE+=	Do.Interface.Wink/do.interface.wink.pc.in
PKGCONFIG_OVERRIDE+=	Do.Interface.Linux.Docky/do.interface.linux.docky.pc.in
PKGCONFIG_OVERRIDE+=	Do.Universe/do.universe.pc.in
PKGCONFIG_OVERRIDE+=	Do.Interface.Linux/do.interface.linux.pc.in
PKGCONFIG_OVERRIDE+=	Do.Interface.Linux.AnimationBase/do.interface.linux.animationbase.pc.in

.include "../../devel/GConf/schemas.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../wip/gnome-keyring-sharp/buildlink3.mk"
.include "../../wip/notify-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
