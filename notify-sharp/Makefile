# $NetBSD: Makefile,v 1.9 2015/07/11 14:33:36 thomasklausner Exp $
#

DISTNAME=	notify-sharp_0.4.0~r3032.orig
PKGNAME=	${DISTNAME:S/_/-/1:S/~//1:S/.orig//1}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.ndesk.org/NotifySharp
COMMENT=	C\# client implementation for Desktop Notifications
LICENSE=	mit

WRKSRC=		${WRKDIR}/notify-sharp-0.4.0
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	notify-sharp.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/ndesk-dbus/buildlink3.mk"
.include "../../sysutils/ndesk-dbus-glib/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
