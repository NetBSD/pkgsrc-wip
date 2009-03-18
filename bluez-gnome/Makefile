# $NetBSD: Makefile,v 1.7 2009/03/18 11:01:33 cheusov Exp $
#

DISTNAME=		bluez-gnome-0.4
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bluez.sourceforge.net/
COMMENT=		BlueZ helpers for Gnome
USE_LANGUAGES=	c
USE_PERL=	YES
USE_TOOLS+=	intltool pkg-config gmake
OWN_DIRS+=		${PKG_SYSCONFDIR}/xdg

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
