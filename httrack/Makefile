# $NetBSD: Makefile,v 1.16 2005/06/17 18:36:06 poppnk Exp $
#

DISTNAME=	httrack-3.33
WRKSRC=         ${WRKDIR}/httrack-3.33.16
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
LDFLAGS+=-L${WRKSRC}/./src/.libs/

SUBST_CLASSES=html
SUBST_STAGE.html=pre-install
SUBST_FILES.html=html/Makefile
SUBST_SED.html=-e 's,install-data-hook,,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
