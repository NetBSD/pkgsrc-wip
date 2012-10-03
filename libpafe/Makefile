# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=	libpafe-0.0.8
CATEGORIES=	misc
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://homepage3.nifty.com/slokar/pasori/libpafe.html
COMMENT=	Library for SONY PaSoRi card reader
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
