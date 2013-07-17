# $NetBSD: Makefile,v 1.1 2013/07/17 12:52:44 obache Exp $
#

DISTNAME=	h323plus-v1_20_2-src
PKGNAME=	h323plus-1.20.2
CATEGORIES=	net
MASTER_SITES=	http://www.h323plus.org/source/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.h323plus.org/source/download/
COMMENT=	Open H.323 library

WRKSRC=		${WRKDIR}/h323plus
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ENV+=		PWLIBDIR=${BUILDLINK_PREFIX.ptlib}/share/ptlib
CONFIGURE_ENV+=		OPENH323DIR=${WRKSRC}
#CONFIGURE_ARGS+=	--disable-versioncheck
CFLAGS+=		-DBOOL=PBoolean
MAKE_ENV+=		BUILD_TYPE=ReleaseCode

BUILD_TARGET=		optdepend optshared

.include "../../devel/ptlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
