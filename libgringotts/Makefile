# $NetBSD: Makefile,v 1.1.1.1 2003/09/04 02:35:08 xtraeme Exp $
#

DISTNAME=	libgringotts-1.2.1
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/libGringotts/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://devel.pluto.linux.it/projects/libGringotts/
COMMENT=	Library for encapsulating data in encrypted form

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../security/libmcrypt/buildlink2.mk"
.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
