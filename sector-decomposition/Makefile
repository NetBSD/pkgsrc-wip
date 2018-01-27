# $NetBSD: Makefile,v 1.3 2012/10/14 18:21:28 asau Exp $
#

DISTNAME=	sector_decomposition-1.1.0
PKGNAME=	sector-decomposition-1.1.0
CATEGORIES=	math
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~stefanw/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~stefanw/sector_decomposition/
COMMENT=	Used to compute numerically the Laurent expansion of Feynman integrals
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

do-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}


.include "../../devel/libltdl/buildlink3.mk"
#.include "../../math/cln/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/libginac/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
