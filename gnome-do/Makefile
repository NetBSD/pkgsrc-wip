# $NetBSD: Makefile,v 1.10 2014/06/01 12:49:36 thomasklausner Exp $
#

DISTNAME=	gnome-do-0.8.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/do/trunk/0.8.5/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://do.davebsd.com/
COMMENT=	Panel replacement
LICENSE=	gnu-gpl-v3

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
.include "../../lang/mono2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gnome-desktop-sharp/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../security/gnome-keyring-sharp/buildlink3.mk"
.include "../../wip/notify-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
