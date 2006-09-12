# $NetBSD: Makefile,v 1.1.1.1 2006/09/12 10:24:18 neimal Exp $
#

DISTNAME=		libmtp-0.0.18
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libmtp/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://libmtp.sourceforge.net/
COMMENT=		Implementation of Media Transfer Protocol (MTP)

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libmtp.pc.in

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
