# $NetBSD: Makefile,v 1.5 2004/02/17 02:55:59 blef Exp $
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
USE_GNU_TOOLS+=	make

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
