# $NetBSD: Makefile,v 1.21 2006/11/11 11:31:04 shattered Exp $
#

DISTNAME=	httrack-3.40-2
PKGNAME=	httrack-3.40.2
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

WRKSRC=		${WRKDIR}/httrack-3.40.3
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
LDFLAGS+=-L${WRKSRC}/./src/.libs/

SUBST_CLASSES+=	html
SUBST_STAGE.html=pre-install
SUBST_FILES.html=html/Makefile
SUBST_SED.html=-e 's,install-data-hook,,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
