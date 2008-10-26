# $NetBSD: Makefile,v 1.9 2008/10/26 19:11:39 minskim Exp $
#

DISTNAME=	e_dbus-0.5.0.050
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-09-25/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.enlightenment.org/snapshots/2008-05-19/
COMMENT=	Convenience wrappers around dbus to ease integrating dbus with E17.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	ehal.pc.in edbus.pc.in enm.pc.in enotify.pc.in

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
