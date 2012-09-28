# $NetBSD: Makefile,v 1.5 2012/09/28 21:24:31 asau Exp $
#

DISTNAME=	dbus-sharp-0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/downloads/mono/dbus-sharp/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mono.github.com/dbus-sharp/
COMMENT=	Fork of ndesk-dbus
LICENSE=	2-clause-bsd # ?

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	dbus-sharp-1.0.pc.in

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
