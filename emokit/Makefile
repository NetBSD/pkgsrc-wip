# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:35 thomasklausner Exp $

DISTNAME=	emokit-0.5
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/openyou/emokit/archive/0.5.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	https://www.openyou.org
COMMENT=	Emotive EPOC EEG development library
LICENSE=	public-domain

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
AUTO_MKDIRS=	yes

post-install:
	${INSTALL} ${WRKSRC}/include/emokit/* ${DESTDIR}${PREFIX}/include/emokit

.include "../../comms/libhidapi/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
