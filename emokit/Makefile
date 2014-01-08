# $NetBSD: Makefile,v 1.1 2014/01/08 12:33:23 nsloss Exp $
DISTNAME=	emokit-0.5
EXTRACT_SUFX=	.zip
CATEGORIES=	devel

MAINTAINER=	nathanialsloss@yahoo.com.au
LICENSE=	public-domain
HOMEPAGE=	https://www.openyou.org
MASTER_SITES=	-https://github.com/openyou/emokit/archive/0.5.zip
COMMENT=	Emotive EPOC EEG development library

FETCH_USING=	curl
AUTO_MKDIRS=	yes
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

post-install:
	${INSTALL} ${WRKSRC}/include/emokit/* ${DESTDIR}${PREFIX}/include/emokit

.include "../../wip/libhidapi/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
