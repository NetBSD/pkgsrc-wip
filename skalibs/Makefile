# $NetBSD$

DISTNAME=	skalibs-2.3.9.0
MASTER_SITES=	http://skarnet.org/software/skalibs/
CATEGORIES=	devel

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The skarnet.org C system programming library
HOMEPAGE=	http://skarnet.org/software/skalibs/
LICENSE=	isc

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"

.include "../../mk/bsd.pkg.mk"
