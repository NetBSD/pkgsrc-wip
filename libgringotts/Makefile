# $NetBSD: Makefile,v 1.3 2003/09/04 18:11:01 xtraeme Exp $
#

DISTNAME=	libgringotts-1.2.1
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/libGringotts/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://devel.pluto.linux.it/projects/libGringotts/
COMMENT=	Library for encapsulating data in encrypted form

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"

pre-install:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.fix
	@${SED} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.fix > \
		${WRKSRC}/Makefile

.endif

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../security/libmcrypt/buildlink2.mk"
.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
