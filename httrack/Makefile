# $NetBSD: Makefile,v 1.1.1.1 2003/04/04 20:52:18 xtraeme Exp $
#

DISTNAME=	httrack-3.23.20
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

WRKSRC=		${WRKDIR}/httrack-3.23.20

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
