# $NetBSD: Makefile,v 1.3 2007/11/24 01:21:45 hoka_adam Exp $
#

DISTNAME=		libmtp-0.2.2
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
