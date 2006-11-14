# $NetBSD: Makefile,v 1.3 2006/11/14 19:20:32 shattered Exp $
#

DISTNAME=		bluez-gnome-0.4
CATEGORIES=		wip
MASTER_SITES=		http://bluez.sourceforge.net/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://bluez.sourceforge.net/
COMMENT=		BlueZ helpers for Gnome
USE_LANGUAGES=	c
USE_PERL=	YES
USE_TOOLS+=	intltool pkg-config gmake

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/GConf2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
