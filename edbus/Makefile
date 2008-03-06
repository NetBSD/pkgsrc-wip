# $NetBSD: Makefile,v 1.4 2008/03/06 14:54:08 thomasklausner Exp $
#

DISTNAME=	e_dbus-0.01
PKGNAME=	${DISTNAME:S/_//}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=   http://www.yazzy.org/pkgsrc/e17/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.enlightenment.org/snapshots/2007-08-26/
COMMENT=	Convenience wrappers around dbus to ease integrating dbus with E17.

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
