# $NetBSD: Makefile,v 1.1.1.1 2010/10/28 14:11:14 hfath Exp $
#

DISTNAME=	CGAL-${DISTVERS}
DISTVERS=	3.7
PKGNAME=	cgal-${DISTVERS}
#PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/27641/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.cgal.org/
COMMENT=	Easy access to efficient and reliable geometric algorithms
LICENSE=	qpl-v1.0 AND gnu-lgpl-v2

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_CMAKE=      yes
USE_LANGUAGES=  c c++

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/glu/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
