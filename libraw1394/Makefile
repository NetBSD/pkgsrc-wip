# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=		libraw1394-0.10.1
CATEGORIES=		multimedia
MASTER_SITES=		http://www.linux1394.org/files/libraw1394/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux1394.org/
COMMENT=		Functions for converting raw1394 protocol packets

ONLY_FOR_PLATFORM=	Linux-*-*


USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libraw1394.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
