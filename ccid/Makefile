# $NetBSD: Makefile,v 1.1.1.1 2005/11/24 15:15:50 udontknow Exp $
#

DISTNAME=		ccid-0.9.3
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/992/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://alioth.debian.org/download.php/992/
COMMENT=	 	USB CCID-compliant smartcard/token driver for pcsc-lite

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/libusb/buildlink3.mk"
.include "../../wip/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
