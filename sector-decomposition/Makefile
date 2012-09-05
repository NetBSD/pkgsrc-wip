# $NetBSD: Makefile,v 1.1 2012/09/05 11:17:55 jihbed Exp $
#

DISTNAME=	sector_decomposition-1.1.0
PKGNAME=	sector-decomposition-1.1.0
CATEGORIES=	math
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~stefanw/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://wwwthep.physik.uni-mainz.de/~stefanw/sector_decomposition/
COMMENT= Used to compute numerically the Laurent expansion of Feynman integrals
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../mk/bsd.pkg.mk"
