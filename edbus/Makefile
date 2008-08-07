# $NetBSD: Makefile,v 1.8 2008/08/07 12:48:07 yazzy Exp $
#

DISTNAME=	e_dbus-0.5.0.043
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-05-19/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-05-19/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.enlightenment.org/snapshots/2008-05-19/
COMMENT=	Convenience wrappers around dbus to ease integrating dbus with E17.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
