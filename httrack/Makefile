# $NetBSD: Makefile,v 1.11 2004/08/17 18:27:51 tvierling Exp $
#

DISTNAME=	httrack-3.32
WRKSRC=         ${WRKDIR}/httrack-3.32.03
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
LIBTOOL_LA_FILES+=	lib/libhttrack.la
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
