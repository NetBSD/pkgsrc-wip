# $NetBSD: Makefile,v 1.5 2008/08/08 13:23:42 thomasklausner Exp $
#

DISTNAME=		libmtp-0.3.0
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

LDFLAGS.FreeBSD+=	-liconv
.include "../../converters/libiconv/buildlink3.mk"

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
