# $NetBSD: Makefile,v 1.15 2007/06/12 04:27:50 obache Exp $
#

DISTNAME=		libupnp-1.6.0-rc1
PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable SDK for Universal Plug and Play (UPnP) Devices

WRKSRC=			${WRKDIR}/${DISTNAME:C/-rc*.$//}

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
