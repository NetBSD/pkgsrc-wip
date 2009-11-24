# $NetBSD: Makefile,v 1.2 2009/11/24 16:12:12 christtrekker Exp $
#

DISTNAME=	edelib-2.0-beta
PKGNAME=	${DISTNAME:S/-beta//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://equinox-project.org/
COMMENT=	Libraries for Equinox Desktop
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/edelib-2.0-beta
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config jam
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	edelib-dbus.pc.in
PKGCONFIG_OVERRIDE+=	edelib-gui.pc.in
PKGCONFIG_OVERRIDE+=	edelib.pc.in

.include "../../mk/bsd.pkg.mk"
