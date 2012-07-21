# $NetBSD: Makefile,v 1.1 2012/07/21 19:06:41 ryo-on Exp $
#

DISTNAME=	libpafe-0.0.8
CATEGORIES=	misc
MASTER_SITES=	http://homepage3.nifty.com/slokar/pasori/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://homepage3.nifty.com/slokar/pasori/libpafe.html
COMMENT=	Library for SONY PaSoRi card reader
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
