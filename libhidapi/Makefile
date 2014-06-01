# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:36 thomasklausner Exp $
PKGNAME=	libhidapi-0.7.0
DISTNAME=	hidapi-0.7.0
CATEGORIES=	devel
COMMENT=	Library for comunicating with bluetooth and usb hid devices

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	http://www.signal11.us/oss/hidapi/
LICENSE=	modified-bsd

EXTRACT_SUFX=	.zip
MASTER_SITES=	-https://github.com/signal11/hidapi/archive/hidapi-0.7.0.zip

USE_TOOLS=	gmake
USE_LANGUAGES=	c c++
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/hidapi-${DISTNAME}

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
