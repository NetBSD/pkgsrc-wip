# $NetBSD$

DISTNAME=	skalibs-2.4.0.1
MASTER_SITES=	http://skarnet.org/software/skalibs/
CATEGORIES=	devel

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The skarnet.org C system programming library
HOMEPAGE=	http://skarnet.org/software/skalibs/
LICENSE=	isc

USE_LANGUAGES=	c
HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

PLIST_VARS+=	include-shared-objects
PLIST.include-shared-objects=	yes

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"

.if "${OPSYS}" == "Darwin"
PLIST.include-shared-objects=	no
CONFIGURE_ARGS+=	"--disable-shared"
.endif

.include "../../mk/bsd.pkg.mk"
