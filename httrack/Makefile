# $NetBSD: Makefile,v 1.3 2003/05/27 12:00:19 xtraeme Exp $
#

DISTNAME=	httrack-3.23
WRKSRC=         ${WRKDIR}/httrack-3.23.20
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/ \
		http://httrack.free.fr/mirror/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.httrack.com/
COMMENT=	Easy-to-use offline browser utility

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
