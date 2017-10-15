# $NetBSD$

DISTNAME=	s6-2.6.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://skarnet.org/software/s6/
LICENSE=	isc

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The s6 supervision suite
HOMEPAGE=	http://skarnet.org/software/s6/

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/execline
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../wip/execline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
