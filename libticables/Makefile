# $NetBSD: Makefile,v 1.1.1.1 2004/03/28 07:00:07 bjan2 Exp $
#

DISTNAME=		libticables
PKGNAME=		libticables-3.7.6
CATEGORIES=		comms
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for communicating with TI calculators

WRKSRC=			${WRKDIR}/${PKGNAME}
LDFLAGS+=		-lintl
LDFLAGS.NetBSD+=	-li386

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
