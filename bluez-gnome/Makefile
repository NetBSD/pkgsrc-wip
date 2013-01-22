# $NetBSD: Makefile,v 1.12 2013/01/22 23:21:22 thomasklausner Exp $
#

DISTNAME=		bluez-gnome-0.4
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bluez.sourceforge.net/
COMMENT=		BlueZ helpers for Gnome
# AND? OR?
#LICENSE=		gnu-gpl-v2 gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_PERL=		YES
USE_TOOLS+=		intltool pkg-config gmake
OWN_DIRS+=		${PKG_SYSCONFDIR}/xdg

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
