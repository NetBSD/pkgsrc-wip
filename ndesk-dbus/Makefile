# $NetBSD: Makefile,v 1.1.1.1 2008/03/17 21:16:08 koifren Exp $

DISTNAME=	ndesk-dbus-0.6.1a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ndesk.org/archive/ndesk-dbus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ndesk.org/DBusSharp
COMMENT=	C\# implementation of dbus

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	ndesk-dbus-1.0.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
