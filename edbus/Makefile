# $NetBSD: Makefile,v 1.1.1.1 2007/12/04 03:50:24 netcap Exp $
#

DISTNAME=	e_dbus-0.1.0.003
PKGNAME=	${DISTNAME:S/_//}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.enlightenment.org/snapshots/2007-08-26/
COMMENT=	E17 library to utilize dbus

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../wip/ecore/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
