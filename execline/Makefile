# $NetBSD$

DISTNAME=	execline-2.3.0.3
CATEGORIES=	devel
MASTER_SITES=	http://skarnet.org/software/execline/
LICENSE=	isc

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The execline scripting language
HOMEPAGE=	http://skarnet.org/software/execline/

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
