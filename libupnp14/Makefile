# $NetBSD: Makefile,v 1.2 2006/06/14 09:55:34 obache Exp $
#

DISTNAME=		libupnp-1.4.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}

MAINTAINER=		obata@lins.jp
HOMEPAGE=		http://www.virtualworlds.de/upnp/
COMMENT=		Portable SDK for Universal Plug and Play (UPnP) Devices

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
