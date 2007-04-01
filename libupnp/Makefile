# $NetBSD: Makefile,v 1.11 2007/04/01 02:19:12 obache Exp $
#

DISTNAME=		libupnp-1.4.3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable SDK for Universal Plug and Play (UPnP) Devices

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin" || ${OPSYS} == "BSDOS"
LIBS+=		-lcompat	# XXX need this for ftime(3)
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
