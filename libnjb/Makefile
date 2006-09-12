# $NetBSD: Makefile,v 1.1.1.1 2006/09/12 08:12:44 neimal Exp $
#

DISTNAME=		libnjb-2.2.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libnjb/}

MAINTAINER=		ku3@sl.aanet.ru
HOMEPAGE=		http://libnjb.sourceforge.net/
COMMENT=		Communicating with some Creative and Dell audio players

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libnjb.pc.in

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
