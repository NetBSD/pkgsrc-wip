# $NetBSD: Makefile,v 1.1.1.1 2009/01/22 16:09:05 rsmarples Exp $
#

DISTNAME=		dhcpcd-gtk-0.1.1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		GTK+ systray monitor for dhcpcd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples/dhcpcd-gtk
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd-gtk.desktop \
			${PKG_SYSCONFDIR}/xdg/autostart/dhcpcd-gtk.desktop

DEPENDS+=		dhcpcd-dbus>=0.1.1:../../wip/dhcpcd-dbus

.include "options.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
