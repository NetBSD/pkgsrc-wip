# $NetBSD: Makefile,v 1.3 2005/04/11 21:13:50 tvierling Exp $
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
USE_GNU_TOOLS+=		make

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
