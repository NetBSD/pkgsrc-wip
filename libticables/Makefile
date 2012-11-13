# $NetBSD: Makefile,v 1.8 2012/11/13 19:33:45 othyro Exp $
#

DISTNAME=		libticables
PKGNAME=		libticables-3.7.6
CATEGORIES=		comms
MASTER_SITES=		http://www.ticalc.org/pub/unix/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tilp.info/
COMMENT=		Library for communicating with TI calculators

PKG_DESTDIR_SUPPORT=	none

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
LDFLAGS+=		-lintl
LDFLAGS.NetBSD+=	-li386

GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
