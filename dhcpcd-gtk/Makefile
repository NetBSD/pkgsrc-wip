# $NetBSD: Makefile,v 1.2 2009/01/22 18:08:37 rsmarples Exp $
#

DISTNAME=		dhcpcd-gtk-0.1.2
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${PREFIX}/share/gnome/autostart

DEPENDS+=		dhcpcd-dbus>=0.1.1:../../wip/dhcpcd-dbus

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
