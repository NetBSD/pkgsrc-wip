# $NetBSD$

DISTNAME=	s6-portable-utils-2.2.1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.skarnet.org/software/s6-portable-utils/

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Tiny portable generic utilties
HOMEPAGE=	http://www.skarnet.org/software/s6-portable-utils/
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
