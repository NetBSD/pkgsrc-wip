# $NetBSD: Makefile,v 1.4 2005/05/24 10:30:38 rillig Exp $
#

DISTNAME=		libticables
PKGNAME=		libticables-3.7.6
CATEGORIES=		comms
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for communicating with TI calculators

WRKSRC=			${WRKDIR}/${PKGNAME}
LDFLAGS+=		-lintl
LDFLAGS.NetBSD+=	-li386

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
