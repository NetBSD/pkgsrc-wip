# $NetBSD: Makefile,v 1.3 2006/11/10 23:16:04 shattered Exp $
#

DISTNAME=		ccid-0.9.3
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/frs/download.php/992/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://alioth.debian.org/frs/download.php/992/
COMMENT=		USB CCID-compliant smartcard/token driver for pcsc-lite

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/libusb/buildlink3.mk"
.include "../../wip/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
