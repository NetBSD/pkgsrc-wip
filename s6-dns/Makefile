# $NetBSD$

DISTNAME=	s6-dns-2.1.0.0
CATEGORIES=	misc
MASTER_SITES=	http://www.skarnet.org/software/s6-dns/

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Suite of DNS client programs and libraries
HOMEPAGE=	http://www.skarnet.org/software/s6-dns/
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
