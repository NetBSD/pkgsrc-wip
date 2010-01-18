# $NetBSD: Makefile,v 1.14 2010/01/18 19:35:46 jsonn Exp $
#

DISTNAME=	e_dbus-0.5.0.063
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-12-02/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	Convenience wrappers around dbus to ease integrating dbus with E17.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	ehal.pc.in edbus.pc.in enm.pc.in enotify.pc.in

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
