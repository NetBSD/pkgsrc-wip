# $NetBSD: Makefile,v 1.13 2004/09/29 23:28:54 poppnk Exp $
#

DISTNAME=	httrack-3.32-2
WRKSRC=         ${WRKDIR}/httrack-3.32.03
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
LIBTOOL_OVERRIDE=${WRKSRC}/libtool
LDFLAGS+=-L${WRKSRC}/./src/.libs/

SUBST_CLASSES=html
SUBST_STAGE.html=pre-install
SUBST_FILES.html=html/Makefile
SUBST_SED.html=-e 's,install-data-hook,,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
