# $NetBSD: Makefile,v 1.1.1.1 2004/06/10 07:17:04 jeremy-c-reed Exp $
#

DISTNAME=		libraw1394-0.10.1
CATEGORIES=		multimedia
MASTER_SITES=		http://www.linux1394.org/files/libraw1394/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.linux1394.org/
COMMENT=		Functions for converting raw1394 protocol packets

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libraw1394.pc.in
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
